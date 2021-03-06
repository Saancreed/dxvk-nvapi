#include "nvapi_private.h"
#include "util/util_statuscode.h"

extern "C" {
    using namespace dxvk;

    NvAPI_Status __cdecl NvAPI_D3D_GetObjectHandleForResource(IUnknown* pDevice, IUnknown* pResource, NVDX_ObjectHandle* pHandle) {
        static bool alreadyLogged = false;
        return NoImplementation("NvAPI_D3D_GetObjectHandleForResource", alreadyLogged);
    }

    NvAPI_Status __cdecl NvAPI_D3D_SetResourceHint(IUnknown *pDev, NVDX_ObjectHandle obj, NVAPI_D3D_SETRESOURCEHINT_CATEGORY dwHintCategory, NvU32 dwHintName, NvU32 *pdwHintValue) {
        static bool alreadyLogged = false;
        return NoImplementation("NvAPI_D3D_SetResourceHint", alreadyLogged);
    }

    NvAPI_Status __cdecl NvAPI_D3D_GetCurrentSLIState(IUnknown* pDevice, NV_GET_CURRENT_SLI_STATE* pSliState) {
        constexpr auto n = "NvAPI_D3D_GetCurrentSLIState";

        if (pDevice == nullptr || pSliState == nullptr)
            return InvalidArgument(n);

        if (pSliState->version != NV_GET_CURRENT_SLI_STATE_VER1 && pSliState->version != NV_GET_CURRENT_SLI_STATE_VER2)
            return IncompatibleStructVersion(n);

        // Report that SLI is not available
        pSliState->maxNumAFRGroups = 1;
        pSliState->numAFRGroups = 1;
        pSliState->currentAFRIndex = 0;
        pSliState->nextFrameAFRIndex = 0;
        pSliState->previousFrameAFRIndex = 0;
        pSliState->bIsCurAFRGroupNew = false;

        if (pSliState->version == NV_GET_CURRENT_SLI_STATE_VER2)
            pSliState->numVRSLIGpus = 0;

        return Ok(n);
    }
}
