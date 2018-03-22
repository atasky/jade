/*
 * pjsip_handler.h
 *
 *  Created on: Dec 13, 2017
 *      Author: pchero
 */

#ifndef SRC_PJSIP_HANDLER_H_
#define SRC_PJSIP_HANDLER_H_

#include <evhtp.h>


bool init_pjsip_handler(void);
bool reload_pjsip_handler(void);
bool term_pjsip_handler(void);

// https handlers
// aor
void htp_get_pjsip_aors(evhtp_request_t *req, void *data);
void htp_post_pjsip_aors(evhtp_request_t *req, void *data);

void htp_get_pjsip_aors_detail(evhtp_request_t *req, void *data);
void htp_put_pjsip_aors_detail(evhtp_request_t *req, void *data);
void htp_delete_pjsip_aors_detail(evhtp_request_t *req, void *data);

// auth
void htp_get_pjsip_auths(evhtp_request_t *req, void *data);
void htp_post_pjsip_auths(evhtp_request_t *req, void *data);

void htp_get_pjsip_auths_detail(evhtp_request_t *req, void *data);
void htp_put_pjsip_auths_detail(evhtp_request_t *req, void *data);
void htp_delete_pjsip_auths_detail(evhtp_request_t *req, void *data);

// contact
void htp_get_pjsip_contacts(evhtp_request_t *req, void *data);
void htp_post_pjsip_contacts(evhtp_request_t *req, void *data);

void htp_get_pjsip_contacts_detail(evhtp_request_t *req, void *data);
void htp_put_pjsip_contacts_detail(evhtp_request_t *req, void *data);
void htp_delete_pjsip_contacts_detail(evhtp_request_t *req, void *data);

// endpoint
void htp_get_pjsip_endpoints(evhtp_request_t *req, void *data);
void htp_post_pjsip_endpoints(evhtp_request_t *req, void *data);

void htp_get_pjsip_endpoints_detail(evhtp_request_t *req, void *data);
void htp_put_pjsip_endpoints_detail(evhtp_request_t *req, void *data);
void htp_delete_pjsip_endpoints_detail(evhtp_request_t *req, void *data);

// identify
void htp_post_pjsip_identifies(evhtp_request_t *req, void *data);

void htp_put_pjsip_identifies_detail(evhtp_request_t *req, void *data);
void htp_delete_pjsip_identifies_detail(evhtp_request_t *req, void *data);

// registration
void htp_post_pjsip_registrations(evhtp_request_t *req, void *data);

void htp_put_pjsip_registrations_detail(evhtp_request_t *req, void *data);
void htp_delete_pjsip_registrations_detail(evhtp_request_t *req, void *data);

// transport
void htp_post_pjsip_transports(evhtp_request_t *req, void *data);

void htp_put_pjsip_transports_detail(evhtp_request_t *req, void *data);
void htp_delete_pjsip_transports_detail(evhtp_request_t *req, void *data);


void htp_get_pjsip_config(evhtp_request_t *req, void *data);
void htp_put_pjsip_config(evhtp_request_t *req, void *data);
void htp_get_pjsip_configs(evhtp_request_t *req, void *data);
void htp_get_pjsip_configs_detail(evhtp_request_t *req, void *data);
void htp_delete_pjsip_configs_detail(evhtp_request_t *req, void *data);

// settings
void htp_get_pjsip_settings_detail(evhtp_request_t *req, void *data);
void htp_put_pjsip_settings_detail(evhtp_request_t *req, void *data);
void htp_delete_pjsip_settings_detail(evhtp_request_t *req, void *data);
void htp_get_pjsip_settings(evhtp_request_t *req, void *data);
void htp_post_pjsip_settings(evhtp_request_t *req, void *data);


// endpoint
bool create_pjsip_endpoint_info(const json_t* j_data);
bool update_pjsip_endpoint_info(const json_t* j_data);
bool delete_pjsip_endpoint_info(const char* key);
json_t* get_pjsip_endpoints_all(void);
json_t* get_pjsip_endpoint_info(const char* name);

// auth
bool create_pjsip_auth_info(const json_t* j_data);
bool update_pjsip_auth_info(const json_t* j_data);
bool delete_pjsip_auth_info(const char* key);
json_t* get_pjsip_auths_all(void);
json_t* get_pjsip_auth_info(const char* key);

// aor
bool create_pjsip_aor_info(const json_t* j_data);
bool update_pjsip_aor_info(const json_t* j_data);
bool delete_pjsip_aor_info(const char* key);
json_t* get_pjsip_aors_all(void);
json_t* get_pjsip_aor_info(const char* key);

// contact
bool create_pjsip_contact_info(const json_t* j_data);
bool update_pjsip_contact_info(const json_t* j_data);
bool delete_pjsip_contact_info(const char* key);
json_t* get_pjsip_contacts_all(void);
json_t* get_pjsip_contact_info(const char* key);


#endif /* SRC_PJSIP_HANDLER_H_ */