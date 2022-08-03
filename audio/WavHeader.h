//Cerate By Kiok Ahn, kiokahn@gazzi.ai
//Home : http://gazzi.ai

//Reference
//https://docs.fileformat.com/audio/wav/
//https://videolan.videolan.me/vlc/vlc__codecs_8h.html

#pragma once

#define 	WAVE_FORMAT_UNKNOWN          0x0000 /* Microsoft Corporation */
#define 	WAVE_FORMAT_PCM              0x0001 /* Microsoft Corporation */
#define 	WAVE_FORMAT_ADPCM            0x0002 /* Microsoft Corporation */
#define 	WAVE_FORMAT_IEEE_FLOAT       0x0003 /* Microsoft Corporation */
#define 	WAVE_FORMAT_ALAW             0x0006 /* Microsoft Corporation */
#define 	WAVE_FORMAT_MULAW            0x0007 /* Microsoft Corporation */
#define 	WAVE_FORMAT_DTS              0x0008 /* Microsoft Corporation */
#define 	WAVE_FORMAT_WMAS             0x000a /* WMA 9 Speech */
#define 	WAVE_FORMAT_IMA_ADPCM        0x0011 /* Intel Corporation */
#define 	WAVE_FORMAT_YAMAHA_ADPCM     0x0020 /* Yamaha */
#define 	WAVE_FORMAT_TRUESPEECH       0x0022 /* TrueSpeech */
#define 	WAVE_FORMAT_GSM610           0x0031 /* Microsoft Corporation */
#define 	WAVE_FORMAT_MSNAUDIO         0x0032 /* Microsoft Corporation */
#define 	WAVE_FORMAT_AMR_NB_2         0x0038 /* AMR NB rogue */
#define 	WAVE_FORMAT_MSG723           0x0042 /* Microsoft G.723 [G723.1] */
#define 	WAVE_FORMAT_SHARP_G726       0x0045 /* ITU-T standard */
#define 	WAVE_FORMAT_MPEG             0x0050 /* Microsoft Corporation */
#define 	WAVE_FORMAT_MPEGLAYER3       0x0055 /* ISO/MPEG Layer3 Format Tag */
#define 	WAVE_FORMAT_AMR_NARROWBAND   0x0057 /* AMR NB */
#define 	WAVE_FORMAT_AMR_WIDEBAND     0x0058 /* AMR Wideband */
#define 	WAVE_FORMAT_G726_ADPCM       0x0064 /* G.726 ADPCM */
#define 	WAVE_FORMAT_VOXWARE_RT29     0x0075 /* VoxWare MetaSound */
#define 	WAVE_FORMAT_DOLBY_AC3_SPDIF  0x0092 /* Sonic Foundry */
#define 	WAVE_FORMAT_VIVOG723         0x0111 /* Vivo G.723.1 */
#define 	WAVE_FORMAT_AAC              0x00FF /* */
#define 	WAVE_FORMAT_AAC_MS           0xa106 /* Microsoft AAC */
// ...

typedef struct
{
    char           Riff        [4];// Marks the file as a riff file. Characters are each 1 byte long.
    unsigned int   FileSize       ;// Size of the overall file - 8 bytes, in bytes (32-bit integer). 
                                   // Typically, you’d fill this in after creation.
    char           FileType    [4];// File Type Header. For our purposes, it always equals “WAVE”.

    char           ChunkMarker [4];// Format chunk marker. Includes trailing null
    unsigned int   FormatLength   ;// Length of format data as listed above
    unsigned short PCMFormat      ;// Type of format (1 is PCM) - 2 byte integer, WAVE_FORMAT_xxx
    unsigned short Channels       ;// Number of Channels - 2 byte integer, Mono = 1, Stereo = 2, etc.
    unsigned int   SampleRate     ;// Sample Rate - 32 byte integer. Common values are 44100 (CD), 48000 (DAT). 
                                   // Sample Rate = Number of Samples per second, or Hertz.
    unsigned int   AvgByteRate    ;// SampleRate * Channels * BitsPerSample/8
    unsigned short BlockAlign     ;// (BitsPerSample * Channels) / 8. 1 - 8 bit mono2 - 8 bit stereo/16 bit mono4 - 16 bit stereo
    unsigned short BitPerSample   ;// Bits per sample, 8 bits = 8, 16 bits = 16, etc

    char           ChunkDATA   [4];// “data” chunk header. Marks the beginning of the data section.
    unsigned int   DataSize       ;// Size of the data section. 
} WAV_HEADER;