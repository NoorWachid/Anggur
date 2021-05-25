#pragma once

#include <string>

struct Mix_Chunk;
struct _Mix_Music;

namespace Anggur {

class Audio
{
public:
    static void SetBuffer(int frequency = 44100, int bufferSize = 128);
    static void SetPollSize(int size);

    static void Initialize();
    static void Terminate();

private:
    static int mFrequency;
    static int mBufferSize;
    static int mPollSize;
};

class SoundFx
{
public:
    SoundFx();
    ~SoundFx();

    void Load(const std::string& path, int slot = -1, int volume = 128);
    void Unload();

    void SetSlot(int slot = -1);
    void SetVolume(int volume = 128);

    void Play();
    void Pause();

    void FadeIn(float time = 0.5);
    void FadeOut(float time = 0.5);

private:
    Mix_Chunk* mChunkData;
    int mVolume;
    int mSlot;
};

class Music
{
public:
    Music();
    ~Music();

    void Load(const std::string& path);
    void Unload();
    void Play();
    void Pause();

private:
    _Mix_Music* mMusicData;
};

}
