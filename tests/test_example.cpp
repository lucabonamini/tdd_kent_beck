#include <gtest/gtest.h>

class Dollar {
  public:
    Dollar(int amount) : amount_(amount) {}
    bool operator==(const Dollar& dollar) const {
      return amount_ == dollar.amount_;
    }
    Dollar times(int multiplier) {
      return Dollar(amount_ * multiplier);
    };
    bool equals(Dollar& dollar) {
      return amount_ == dollar.amount_;
    }
  private:
    int amount_;
};

TEST(MoneyExample, TestMultiplication) {
  Dollar five(5);
  ASSERT_EQ(Dollar(10), five.times(2));
  ASSERT_EQ(Dollar(15), five.times(3));
}

TEST(MoneyExample, Equality) {
  Dollar five_1(5);
  Dollar five_2(5);
  Dollar six(6);
  ASSERT_TRUE(five_1.equals(five_2));
  ASSERT_FALSE(five_1.equals(six));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}