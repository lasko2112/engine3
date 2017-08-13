//
// Created by Victor Popovici on 8/4/17.
//

#include "MetricsManager.h"

using namespace engine::core;

MetricsManager::MetricsManager() : Logger("MetricsManager"), client(NULL) {
}

void MetricsManager::initializeStatsDConnection(const char* hostname, int port) {
	client = new DatagramServiceClient(hostname, port);
}

MetricsManager::Result MetricsManager::publish(const Metrics& metrics) {
	return publish(metrics.name, metrics.value, metrics.type, metrics.sampleTime);
}

MetricsManager::Result MetricsManager::publish(const char* name, const char* value, const char* type, const char* sampleTime) {
	if (client == NULL) {
		return NO_CONNECTION;
	}

	try {
		Packet pack(64);

		pack.insertCString(name);
		pack.insertCString(":");
		pack.insertCString(value);
		pack.insertCString("|");
		pack.insertCString(type);

		if (sampleTime) {
			pack.insertCString("|@");
			pack.insertCString(sampleTime);
		}

		pack.insertByte(0);

		client->send(&pack);
	} catch (const SocketException& exc) {
		error(exc.getMessage());

		return SOCKET_EXCEPTION;
	}

	return SUCCESS;
}
