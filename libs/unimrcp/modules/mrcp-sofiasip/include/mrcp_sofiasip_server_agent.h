/*
 * Copyright 2008-2010 Arsen Chaloyan
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * $Id: mrcp_sofiasip_server_agent.h 1700 2010-05-21 18:56:06Z achaloyan $
 */

#ifndef MRCP_SOFIASIP_SERVER_AGENT_H
#define MRCP_SOFIASIP_SERVER_AGENT_H

/**
 * @file mrcp_sofiasip_server_agent.h
 * @brief Implementation of MRCP Signaling Interface using Sofia-SIP
 */ 

#include <apr_network_io.h>
#include "mrcp_sig_agent.h"

APT_BEGIN_EXTERN_C

/** Sofia-SIP config declaration */
typedef struct mrcp_sofia_server_config_t mrcp_sofia_server_config_t;

/** Sofia-SIP config */
struct mrcp_sofia_server_config_t {
	/** Local IP address to bind to */
	char      *local_ip;
	/** External (NAT) IP address */
	char      *ext_ip;
	/** Local port to bind to */
	apr_port_t local_port;
	/** SIP user name */
	char      *user_name;
	/** User agent name */
	char      *user_agent_name;
	/** SDP origin */
	char      *origin;
	/** SIP transport */
	char      *transport;
	/** Force destination ip address. Should be used only in case 
	SDP contains incorrect connection address (local IP address behind NAT) */
	apt_bool_t force_destination;
	/** SIP T1 timer */
	apr_size_t sip_t1;
	/** SIP T2 timer */
	apr_size_t sip_t2;
	/** SIP T4 timer */
	apr_size_t sip_t4;
	/** SIP T1x64 timer */
	apr_size_t sip_t1x64;
};

/**
 * Create Sofia-SIP signaling agent.
 */
MRCP_DECLARE(mrcp_sig_agent_t*) mrcp_sofiasip_server_agent_create(const char *id, mrcp_sofia_server_config_t *config, apr_pool_t *pool);

/**
 * Allocate Sofia-SIP config.
 */
MRCP_DECLARE(mrcp_sofia_server_config_t*) mrcp_sofiasip_server_config_alloc(apr_pool_t *pool);

APT_END_EXTERN_C

#endif /* MRCP_SOFIASIP_SERVER_AGENT_H */
