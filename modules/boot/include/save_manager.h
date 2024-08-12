#pragma once

#include "commands.h"
#include <boot/include/utils/containers/deque.h>
#include "libtww/include/dolphin/mtx/vec.h"
#include "libtww/include/d/com/d_com_inf_game.h"

#ifdef NTSCJ
#define sTmpBuf 0x803a8540
#endif

#ifdef NTSCU
#define sTmpBuf 0x803b5040
#endif

#ifdef PAL
#define sTmpBuf 0x803bbd40
#endif

#define MEMFILE_BUF ((void*)sTmpBuf)

typedef void (*LoadingCallback)(void);

class special {
public:
    special(int i_idx, LoadingCallback cb) {
        idx = i_idx;
        loadingCallback = cb;
    }

    uint32_t idx;
    LoadingCallback loadingCallback;

private:
};

struct PracticeFileOpts {
    void (*inject_options_before_load)();
    void (*inject_options_during_load)();
    void (*inject_options_after_load)();
    int inject_options_after_counter = 0;
};

struct PracticeSaveInfo {
    uint8_t requirements;
    uint8_t _p0[1];
    uint16_t angle;
    Vec position;
    Vec cam_pos;
    Vec cam_target;
    uint32_t counter;
    char filename[32];
    uint8_t _p1[4];
} __attribute__((packed));

typedef void (*ActorModCallback)(fopAc_ac_c* actor);

struct ActorModEntry {
    u32 id;
    u16 attempts;
    s16 procName;
    ActorModCallback callback;
    fopAc_ac_c* actor;
};
class SaveManager {
public:
    PracticeFileOpts mPracticeFileOpts;
    PracticeSaveInfo mPracticeSaveInfo __attribute__((aligned(32)));
    special* mSpecials;

    static bool s_injectSave;

public:
    static void injectSave(void* buffer);
    static void injectDefault_before();
    static void injectDefault_during();
    static void injectDefault_after();
    static void loadSave(uint32_t id, const char* category, special* i_specials = nullptr, int size = 0);
    static void loadSavefile(const char* fileName);
    static void triggerLoad(uint32_t id, const char* category, special i_specials[], int size);
    static void defaultLoad();

    static void loadData();

    void modifySave(LoadingCallback cb) { mPracticeFileOpts.inject_options_after_load = cb; }

    void modifyActor(s16 procName, ActorModCallback callback) {
        mDeque.push_back({mCurEntryId, 0, procName, callback});
        mCurEntryId++;
    }

    void RemoveActorModRequest(u32 id);
    void ProcessActorModRequests();

private:
    u32 mCurEntryId;
    twwgz::containers::deque<ActorModEntry> mDeque;
};

extern SaveManager gSaveManager;
