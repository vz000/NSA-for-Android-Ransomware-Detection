// estatic-v1.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// TODO: Reference additional headers your program requires here.
class StaticData {
	std::vector<std::string> rawPermissions;

public:
	std::vector<std::string> getPermissions() {
		fetchPermissions();
		return rawPermissions;
	};

private:
	void fetchPermissions() {
		std::ifstream manifest;
		std::string line, permission;
		std::string permissionLine("uses-permission: name='");

		manifest.open("aaptOut.txt");
		if (manifest.is_open()) {
			while (std::getline(manifest, line)) {
				if (line.find(permissionLine) != std::string::npos) {
					std::size_t pos = line.find(permissionLine) + permissionLine.length();
					permission = line.substr(pos);
					permission = permission.substr(0, permission.length() - 1);
					permission = split(permission);

					rawPermissions.push_back(permission);
				}
			}
		}
	};

	std::string split(std::string& rawData) {
		std::size_t pos = 0;
		std::string token;
		while ((pos = rawData.find(".")) != std::string::npos) {
			token = rawData.substr(0, pos);
			rawData.erase(0, pos + 1);
		}

		return rawData;
	}
};
