#pragma once
#include "GameData.h"
#include "GameImpl.h"
#include "ForceImpl.h"
#include "PlayerImpl.h"
#include "UnitImpl.h"
#include "GameTable.h"

#include "../WindowsTypes.h"

/* Added, because the default implementation
 * put to much stuff to stdout and stderr.
 *
 * BWAPI_CLIENT_VERBOSITY:
 *      0  - no output
 *      1  - stdout
 *      2  - stderr
 * (1 | 2) - both
 */
#define BWAPI_CLIENT_VERBOSITY 0

namespace BWAPI
{
  class Client
  {
  public:
    Client();
    ~Client();

    bool isConnected() const;
    bool connect();
    void disconnect();
    void update();

    GameData* data = nullptr;
  private:
    HANDLE      pipeObjectHandle;
    HANDLE      mapFileHandle;
    HANDLE      gameTableFileHandle;
    GameTable*  gameTable = nullptr;
    
    bool connected = false;
  };
  extern Client BWAPIClient;
}
