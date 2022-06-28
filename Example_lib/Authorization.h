//
// Created by Adrian Garro on 27/6/22.
//

#include <string>
#include <vector>

using std::string;
using std::vector;

#ifndef TESTING_TEST_AUTHORIZATION_H
#define TESTING_TEST_AUTHORIZATION_H

class Authorization {
    public:
        virtual bool create_user(string username, string password) = 0;
        virtual vector<string> get_users() = 0;
};

#endif //TESTING_TEST_AUTHORIZATION_H
