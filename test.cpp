#include "googletest/include/gtest/gtest.h"
#include "set.h"
#include <iostream>

using namespace std;



   TEST(TestGroupSearch, Constr_Default1){
   Set A(10,20);
   A.add(11);
     ASSERT_TRUE(A.search(11));
   }
   TEST(TestGroupDell, Constr_Default1){
   Set A(10,20);
   A.add(11);
   A.add(12);
   A.del(12);
     ASSERT_TRUE(A.search(11));
      ASSERT_FALSE(A.search(12));
   }
   TEST(TestGroup1, Constr_Default1){
   Set A(10,20);
   A.add(11);
   A.add(12);
   Set B(10,20);
   B.add(12);
   B.add(13);
   Set C=A*B;
     ASSERT_TRUE(C.search(12));
     ASSERT_FALSE(C.search(11));
     ASSERT_FALSE(C.search(13));
   }
   TEST(TestGroup2, Constr_Default1){
   Set A(10,20);
   A.add(11);
   Set B(10,20);
   B.add(12);
   Set C=A+B;
     ASSERT_TRUE(C.search(12));
     ASSERT_TRUE(C.search(11));
     ASSERT_FALSE(C.search(13));
   }
  TEST(TestGroup3, Constr_Default1){
   Set A(10,20);
   A.add(11);
   A.add(12);
   A.add(13);
   Set B(10,20);
   B.add(12);
   B.add(11);
   Set C=A-B;
     ASSERT_FALSE(C.search(12));
     ASSERT_FALSE(C.search(11));
     ASSERT_TRUE(C.search(13));
   }
TEST(TestGroup4, Constr_Default1){
   Set A(10,15);
   A.add(11);
   A.add(12);
   A.add(13);
    Set B=~A;
     ASSERT_FALSE(B.search(12));
     ASSERT_FALSE(B.search(11));
     ASSERT_FALSE(B.search(13));
     ASSERT_TRUE(B.search(14));
     ASSERT_TRUE(B.search(15));
   }


int main(int argc, char **argv){
   ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
     }