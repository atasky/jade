/*
 * agent_handler.c
 *
 *  Created on: Dec 12, 2017
 *      Author: pchero
 */


#include <jansson.h>

#include "http_handler.h"
#include "resource_handler.h"
#include "slog.h"


/**
 * GET ^/agent/agents request handler.
 * @param req
 * @param data
 */
void htp_get_agent_agents(evhtp_request_t *req, void *data)
{
  json_t* j_res;
  json_t* j_tmp;

  if(req == NULL) {
    slog(LOG_WARNING, "Wrong input parameter.");
    return;
  }
  slog(LOG_INFO, "Fired htp_get_agent_agents.");

  j_tmp = get_agents_all();
  if(j_tmp == NULL) {
    simple_response_error(req, EVHTP_RES_SERVERR, 0, NULL);
    return;
  }

  // create result
  j_res = create_default_result(EVHTP_RES_OK);
  json_object_set_new(j_res, "result", json_object());
  json_object_set_new(json_object_get(j_res, "result"), "list", j_tmp);

  simple_response_normal(req, j_res);
  json_decref(j_res);

  return;
}


/**
 * GET ^/agent/agents/(*) request handler.
 * @param req
 * @param data
 */
void htp_get_agent_agents_detail(evhtp_request_t *req, void *data)
{
  json_t* j_res;
  json_t* j_tmp;
  const char* id;

  if(req == NULL) {
    slog(LOG_WARNING, "Wrong input parameter.");
    return;
  }
  slog(LOG_INFO, "Fired htp_get_agent_agents_detail.");

  // get id
  id = req->uri->path->file;
  if(id == NULL) {
    slog(LOG_NOTICE, "Could not get id info.");
    simple_response_error(req, EVHTP_RES_BADREQ, 0, NULL);
    return;
  }

  // get channel info.
  j_tmp = get_agent_info(id);
  if(j_tmp == NULL) {
    slog(LOG_NOTICE, "Could not get agent info.");
    simple_response_error(req, EVHTP_RES_NOTFOUND, 0, NULL);
    return;
  }

  // create result
  j_res = create_default_result(EVHTP_RES_OK);
  json_object_set_new(j_res, "result", j_tmp);

  simple_response_normal(req, j_res);
  json_decref(j_res);

  return;
}

