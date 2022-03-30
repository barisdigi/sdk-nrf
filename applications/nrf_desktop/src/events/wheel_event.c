/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <stdio.h>

#include "wheel_event.h"

static void log_wheel_event(const struct application_event_header *aeh)
{
	const struct wheel_event *event = cast_wheel_event(aeh);

	APP_EVENT_MANAGER_LOG(aeh, "wheel=%d", event->wheel);
}

APPLICATION_EVENT_TYPE_DEFINE(wheel_event,
		  log_wheel_event,
		  NULL,
		  APPLICATION_EVENT_FLAGS_CREATE(
			IF_ENABLED(CONFIG_DESKTOP_INIT_LOG_WHEEL_EVENT,
				(APPLICATION_EVENT_TYPE_FLAGS_INIT_LOG_ENABLE))));
