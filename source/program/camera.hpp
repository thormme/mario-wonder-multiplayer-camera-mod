#include "lib.hpp"
#include "external.hpp"
#include "symbols.hpp"

HOOK_DEFINE_INLINE(ModifyCameraPosition) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        // patch first check to always treat the encounter table as valid
        // this allows spawners with empty/invalid tables to make it to the SwapSymbolTableHash trampoline
        // & is harmless as GenerateSymbolEncountParam re-checks validity

        GlobalGameData_t* globalGameData = (GlobalGameData_t*) ctx->X[19];

        int playerId = 1;
        PlayerData_t* p1Data = CameraMod::GetPlayerData(&playerId);
        // playerId = 1;
        // PlayerData_t* p2Data = CameraMod::GetPlayerData(&playerId);
        float avgX = (p1Data->position.x);
        float avgY = (p1Data->position.y);
        // if (p2Data != nullptr) {
        //     avgX = (p1Data->position.x + p2Data->position.x) / 2;
        //     avgY = (p1Data->position.y + p2Data->position.y) / 2;
        // }
        globalGameData->cameraMidX = avgX;
        globalGameData->cameraMidY = avgY;
    }
};

void install_camera_patch() {
    ModifyCameraPosition::InstallAtOffset(CameraMod::UpdateCameraPosition_BeforeUpdateBounds_offset);
}
