//
// Created by Adrian Garro on 27/6/22.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "AuthorizationManager.h"

class AuthorizationStub : public Authorization {
    public:
        AuthorizationStub() = default;

        bool create_user(string username, string password) override {
            return true;
        }

        vector<string> get_users() override {
            vector<string> users;
            users.emplace_back("james");
            users.emplace_back("gabriel");
            users.emplace_back("kevin");
            return users;
        }
};

class AuthorizationMock : public Authorization {
    public:
        MOCK_METHOD(bool , create_user, (string username, string password), (override));
        MOCK_METHOD(vector<string>, get_users, (), (override));
};

// STUB TESTS:

// Given an authorization manager
// When the method create a user is called
// Then the call shall be able to get a successful response
TEST(Authorization, CreateUser) {
    AuthorizationManager authManager(new AuthorizationStub());
    bool success = authManager.create_user("adrian", "1234$");
    EXPECT_EQ(success, true);
}

// Given an authorization manager
// When the method get users is called
// Then the call shall be able to get the expected response
TEST(Authorization, GetUsers) {
    AuthorizationManager authManager(new AuthorizationStub());
    vector<string> users = authManager.get_users();
    EXPECT_EQ(users[0], "james");
    EXPECT_EQ(users[1], "gabriel");
    EXPECT_EQ(users[2], "kevin");
}

// MOCK TESTS:

TEST(Authorization, CreateUser_Mock) {
    //AuthorizationMock authorizationMock;
    //EXPECT_CALL(authorizationMock, create_user("adrian", "1234$")).WillOnce(testing::Return(true));
    //AuthorizationManager authManager(&authorizationMock);
    //EXPECT_TRUE(authManager.create_user("adrian", "1234$"));
}

/*TEST(Authorization, GetUsers_Mock) {
    AuthorizationMock authorizationMock;
    vector<string> users;
    users.emplace_back("james");
    users.emplace_back("gabriel");
    users.emplace_back("kevin");
    AuthorizationManager authManager(&authorizationMock);
    EXPECT_CALL(authManager, get_users()).WillOnce(testing::Return(users));
    vector<string> users_returned = authManager.get_users();
    EXPECT_EQ(users_returned[0], "james");
    EXPECT_EQ(users_returned[1], "gabriel");
    EXPECT_EQ(users_returned[2], "kevin");
}*/
