//
// Created by Adrian Garro on 27/6/22.
//

#include <iostream>
#include <utility>
#include <vector>
#include "Authorization.h"

using std::cout;
using std::string;
using std::vector;
using std::endl;

#ifndef TESTING_TEST_AUTHORIZATION_MANAGER_H
#define TESTING_TEST_AUTHORIZATION_MANAGER_H

class AuthorizationManager {
private:
    Authorization *auth = nullptr;
public:
    explicit AuthorizationManager(Authorization *pAuth) {
        auth = pAuth;
    }

    bool create_user(const string& username, const string& password) {
        if (auth->create_user(username, password)) {
            cout << "User " << username << " created successfully" << endl;
            return true;
        } else {
            cout << "Failed to create user " << username << endl;
            return false;
        }
    }

    vector<string> get_users() {
        cout << "List of users: " << endl;
        vector<string> users = auth->get_users();
        for (auto &user : users) {
            cout << user << endl;
        }
        return auth->get_users();
    }
};

#endif //TESTING_TEST_AUTHORIZATION_MANAGER_H
