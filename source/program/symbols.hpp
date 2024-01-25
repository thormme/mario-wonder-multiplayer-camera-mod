#include "external.hpp"

#ifndef SYMBOLS_HPP
#define SYMBOLS_HPP

typedef struct {
    float x;
    float y;
    float z;
} Vector3_t;

typedef struct {
    u8 data[0x50];
    float cameraBoundMinX;
    float cameraBoundMinY;
    float cameraBoundMaxX;
    float cameraBoundMaxY;
    float cameraMidX;
    float cameraMidY;
    u8 data_2[0x18];
    float playerX;
    float playerY;
    u8 data_3[0x1BC];
    Vector3_t playerPosition;
} GlobalGameData_t;

typedef struct {
    u8 data[0x38];
    Vector3_t altPosition;
    Vector3_t position;
} PlayerData_t;

namespace CameraMod {
    #ifdef VERSION_1_0_0
    static const u64 UpdateCameraPosition_offset = 0x238C84;
    static const u64 UpdateCameraPosition_BeforeUpdateBounds_offset = UpdateCameraPosition_offset + 0x64;
    static const u64 GetPlayerData_offset = 0x2EFB80;
    #else
    // TODO: 1.0.1 offsets
    static const u64 UpdateCameraPosition_offset = 0x238C84;
    static const u64 UpdateCameraPosition_BeforeUpdateBounds_offset = UpdateCameraPosition_offset + 0x64;
    static const u64 GetPlayerData_offset = 0x2EFB80;
    #endif
    
    static PlayerData_t* GetPlayerData(int* player_id) {
        return external<PlayerData_t*>(GetPlayerData_offset, player_id);
    }
}
#endif
