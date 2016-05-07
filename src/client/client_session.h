/*
 * This file is part of iprohc.
 *
 * iprohc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * any later version.
 *
 * iprohc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with iprohc.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file   client_session.h
 * @brief  The context of the session at client
 * @author Didier Barvaux <didier.barvaux@toulouse.viveris.com>
 */

#ifndef IPROHC_CLIENT_SESSION__H
#define IPROHC_CLIENT_SESSION__H

#include "session.h"

#include <limits.h>
#include <net/if.h>

/** The context of the session at client */
struct iprohc_client_session
{
	gnutls_certificate_credentials_t tls_cred;

	struct iprohc_session session; /**< The generic session context */

	/** The packing level that client wishes to enforce */
	size_t packing;

	/** The netfilter firewall mark (no mark if 0) */
	int fwmark;

	char tun_name[IFNAMSIZ];       /**< The name of the TUN interface */
	int tun;
	int tun_itf_id;
	size_t tun_itf_mtu;            /**< The MTU of the TUN interface */

	int raw;

	char basedev[IFNAMSIZ];            /**< The name of the base interface */
	size_t basedev_mtu;                /** The MTU of the base interface */

	char up_script_path[PATH_MAX + 1]; /**< The path to the UP script */
};

#endif

