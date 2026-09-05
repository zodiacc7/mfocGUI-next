#pragma once
#ifndef MFOCH_H
#define MFOCH_H

#include <SDKDDKVer.h>
#include <cstddef>
#include <cstdint>

#ifndef PTRDIFF_MAX
#define PTRDIFF_MAX INTPTR_MAX
#endif

#include <nfc/nfc.h>

#include <list>

#define u_int32_t uint32_t

#define MEM_CHUNK               10000
#define TRY_KEYS                150

#define NR_TRAILERS_1k  (16)
#define NR_TRAILERS_4k  (40)

#define MAX_FRAME_LEN 264
#define DEFAULT_TOLERANCE       20
#define DEFAULT_DIST_NR         15
#define DEFAULT_PROBES_NR       600
#define DEFAULT_SETS_NR         2

#define odd_parity(i) (( (i) ^ (i)>>1 ^ (i)>>2 ^ (i)>>3 ^ (i)>>4 ^ (i)>>5 ^ (i)>>6 ^ (i)>>7 ^ 1) & 0x01)

typedef struct { byte_t KeyA[6]; byte_t KeyB[6]; bool foundKeyA; bool foundKeyB; byte_t trailer; } sector;
typedef struct { uint32_t *distances; uint32_t median; uint32_t num_distances; uint32_t tolerance; byte_t parity[3]; } denonce;
typedef struct { nfc_target_t ti; sector *sectors; sector e_sector; uint32_t num_sectors; uint32_t num_blocks; uint32_t uid; bool b4K; } mftag;
typedef struct { uint64_t *possibleKeys; uint32_t size; } pKeys;
typedef struct { uint64_t *brokenKeys; uint32_t size; } bKeys;
typedef struct { nfc_device_t *pdi; } mfreader;
typedef struct { uint64_t key; int count; } countKeys;
typedef struct { uint8_t sector; byte_t KeyA[6]; byte_t KeyB[6]; byte_t Data[16][16]; } mifare_sector;
typedef struct { char keyType; int sector; int probe; int set; unsigned __int64 duration; } performance;

extern bool stopreadingcard;

int ReadCard(nfc_device_desc_t *device, std::list<performance> *performanceData, int sets, char *keyDir, unsigned char *buffer, int buffersize, int skipToSector, bool keyA, bool keyB, void (*UpdateSectorStatus)(char, int, byte_t), void (*UpdateStatusMessage)(char *status), void (*SetCardInfo)(char *status));
int WriteCard(nfc_device_desc_t *device, char *keyDir, unsigned char *buffer, int buffersize, bool keyA, bool keyB, bool writeKeys, void (*UpdateSectorStatus)(char, int, byte_t), void (*UpdateStatusMessage)(char *status), void (*SetCardInfo)(char *status));
#endif