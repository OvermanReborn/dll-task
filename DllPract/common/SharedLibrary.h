#pragma once

#include <stdexcept>
#include <string>
#include <type_traits>

#ifdef _WIN32
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif

class SharedLibrary {
public:
    explicit SharedLibrary(const char* path) {
        if (!path || !*path) {
            throw std::runtime_error("Library path is empty");
        }

#ifdef _WIN32
        handle_ = LoadLibraryA(path);
        if (!handle_) {
            const auto error = GetLastError();
            throw std::runtime_error(
                std::string("Cannot load library: ") + path +
                " (Windows error " + std::to_string(error) + ")"
            );
        }
#else
        handle_ = dlopen(path, RTLD_NOW | RTLD_LOCAL);
        if (!handle_) {
            const char* error = dlerror();
            throw std::runtime_error(
                std::string("Cannot load library: ") + path +
                ": " + (error ? error : "unknown error")
            );
        }
#endif
    }

    ~SharedLibrary() noexcept {
        if (handle_) {
#ifdef _WIN32
            FreeLibrary(handle_);
#else
            dlclose(handle_);
#endif
        }
    }

    SharedLibrary(const SharedLibrary&) = delete;
    SharedLibrary& operator=(const SharedLibrary&) = delete;
    SharedLibrary(SharedLibrary&&) = delete;
    SharedLibrary& operator=(SharedLibrary&&) = delete;

    template<typename T>
    T get(const char* name) const {
        static_assert(
            std::is_pointer_v<T> &&
            std::is_function_v<std::remove_pointer_t<T>>,
            "T must be a function pointer"
        );

        if (!name || !*name) {
            throw std::runtime_error("Function name is empty");
        }

#ifdef _WIN32
        auto address = GetProcAddress(handle_, name);
        if (!address) {
            const auto error = GetLastError();
            throw std::runtime_error(
                std::string("Cannot find function: ") + name +
                " (Windows error " + std::to_string(error) + ")"
            );
        }
#else
        dlerror();
        void* address = dlsym(handle_, name);
        const char* error = dlerror();

        if (error) {
            throw std::runtime_error(
                std::string("Cannot find function: ") + name +
                ": " + error
            );
        }

        if (!address) {
            throw std::runtime_error(
                std::string("Function address is null: ") + name
            );
        }
#endif

        return reinterpret_cast<T>(address);
    }

private:
#ifdef _WIN32
    HMODULE handle_ = nullptr;
#else
    void* handle_ = nullptr;
#endif
};
