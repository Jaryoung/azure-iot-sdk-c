// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef HSM_CLIENT_EDGE_H
#define HSM_CLIENT_EDGE_H

#ifdef __cplusplus
extern "C" {
#include <cstdint>
#include <cstddef>
#else
#include <stdint.h>
#include <stddef.h>
#endif /* __cplusplus */

#include "azure_c_shared_utility/umock_c_prod.h"
#include "azure_c_shared_utility/macro_utils.h"
#include "hsm_client_data.h"

MOCKABLE_FUNCTION(, HSM_CLIENT_HANDLE, hsm_client_http_edge_create);
MOCKABLE_FUNCTION(, void, hsm_client_http_edge_destroy, HSM_CLIENT_HANDLE, handle);
MOCKABLE_FUNCTION(, int, hsm_client_http_edge_get_endorsement_key, HSM_CLIENT_HANDLE, handle, unsigned char**, key, size_t*, key_len);
MOCKABLE_FUNCTION(, int, hsm_client_http_edge_get_storage_key, HSM_CLIENT_HANDLE, handle, unsigned char**, key, size_t*, key_len);
MOCKABLE_FUNCTION(, int, hsm_client_http_edge_import_key, HSM_CLIENT_HANDLE, handle, const unsigned char*, key, size_t, key_len);
MOCKABLE_FUNCTION(, int, hsm_client_http_edge_sign_data, HSM_CLIENT_HANDLE, handle, const unsigned char*, data, size_t, data_len, unsigned char**, signed_value, size_t*, signed_len);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // HSM_CLIENT_EDGE_H
