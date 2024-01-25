#include "lib.hpp"
#include "camera.hpp"

extern "C" void exl_main(void* x0, void* x1) {
    exl::hook::Initialize();
    
    install_camera_patch();
}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}