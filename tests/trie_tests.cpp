//
// Created by Maurice on 16/08/2024.
//

#include <gtest/gtest.h>
#include <iostream>

TEST(complex_datastructure,test1){
    ASSERT_EQ(2,2);
}

TEST(complex_datastructure,test2){
ASSERT_EQ(2,2);
}

int main(int argc,char** argv ){
    std::cout << "hello world" << std::endl;

    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}