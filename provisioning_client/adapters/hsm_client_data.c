// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdlib.h>

#include "azure_c_shared_utility/xlogging.h"

#include "hsm_client_tpm.h"
#include "hsm_client_riot.h"

int initialize_hsm_system()
{
    int result;
    // Initialize x509
    if (hsm_client_x509_init() != 0)
    {
        LogError("Failure initializing x509 system");
        result = __LINE__;
    }
    else if (hsm_client_tpm_init() != 0)
    {
        LogError("Failure initializing tpm system");
        result = __LINE__;
    }
#ifdef HSM_TYPE_HTTP_EDGE
    else if (hsm_client_http_edge_init() != 0)
    {
        LogError("Failure initializing http edge system");
        result = __LINE__;
    }
#endif
    else
    {
        result = 0;
    }
    return result;
}

void deinitialize_hsm_system()
{
#ifdef HSM_TYPE_HTTP_EDGE
    hsm_client_http_edge_deinit();
#endif
    hsm_client_tpm_deinit();
    hsm_client_x509_deinit();
}
