#include <gtest/gtest.h>

extern "C"
{
	void myputchar(int c);
}
void myputchar(int c)
{
}

#include "../myprintf.h"

#define PRINTF(format,arg,expected) { char buf[100]; mysprintf(buf,format,arg); EXPECT_STREQ(buf,expected); }

TEST(myprintf, decimal_pos)
{
	PRINTF("%x", 0xa, "a");
	PRINTF("%d", 10, "10");
}
TEST(myprintf, decimal_neg)
{
	PRINTF("%d", -10, "-10");
}
TEST(myprintf, decimal_width)
{
	PRINTF("%5d", 10, "   10");
}

TEST(myprintf, float_def)
{
	PRINTF("%f", 1.23, "1.230000");
	PRINTF("%f", 1.234567, "1.234567");
	PRINTF("%f", 1.2345678, "1.234568");
	PRINTF("%f", 1.2345670, "1.234567");
	PRINTF("%f", 1.000567, "1.000567");
}
TEST(myprintf, float_width)
{
	PRINTF("%2f", 1.23, "1.23");

	PRINTF("%3f", 0.010, "0.010");

	PRINTF("%4f", 0.0155, "0.0155");
}
TEST(myprintf, float_round)
{
	PRINTF("%2f", 1.000, "1.00");
	PRINTF("%1f", 1.000, "1.0");

	PRINTF("%2f", 0.900, "0.90");
	PRINTF("%1f", 0.900, "0.9");

	PRINTF("%1f", 0.550, "0.6");

	PRINTF("%2f", 0.950, "0.95");
	PRINTF("%1f", 0.950, "1.0");

	PRINTF("%4f", 0.010, "0.0100");
	PRINTF("%3f", 0.010, "0.010");
	PRINTF("%2f", 0.010, "0.01");
	PRINTF("%1f", 0.010, "0.0");

	PRINTF("%2f", 1.236, "1.24");

	PRINTF("%4f", 0.0155, "0.0155");
	PRINTF("%3f", 0.0155, "0.016");
	PRINTF("%2f", 0.0155, "0.02");

	PRINTF("%3f", 0.0135, "0.014");
	PRINTF("%2f", 0.0135, "0.01");
}
TEST(myprintf, float_round_neg)
{
	PRINTF("%1f", -0.97, "-1.0");
}
TEST(myprintf, float_neg_space)
{
	PRINTF("%6f", 1.1234, "1.123400");
	PRINTF("%-6f", 1.1234, " 1.123400");
}
TEST(myprintf, other)
{
	PRINTF("%9f", 1.066856831, "1.066856831");
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
