#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Chat.h"
#include "Group.h"

class cs_mmr : public CommandScript
{
public:
    cs_mmr() : CommandScript("cs_mmr") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand testCommandTable[] =
        {
            { "command",            SEC_PLAYER,  false, &HandleTestCommand,             "", NULL },
            { NULL,             0,                  false, NULL,                              "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "test",           SEC_PLAYER,      true, NULL,                   "", testCommandTable },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }

    static bool HandleTestCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();

            me->Say("test command?", LANG_UNIVERSAL);
            return true;
    }
};

void AddSC_cs_mmr()
{
    new cs_mmr();
}