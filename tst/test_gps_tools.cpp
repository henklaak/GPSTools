#include <gps_tools/gps_tools.h>
#include <gtest/gtest.h>

/**************************************************************************************************/
TEST(TestGpsTools, DefaultConstructor) {
  GpsTools::GpsPosition bla;

  EXPECT_EQ(bla.latitude, 0.0);
  EXPECT_EQ(bla.longitude, 0.0);
  EXPECT_EQ(bla.elevation, 0.0);
}

/**************************************************************************************************/
TEST(TestGpsTools, ConstructorTwoArgs) {
  GpsTools::GpsPosition bla(1, 2);

  EXPECT_EQ(bla.latitude, 1.0);
  EXPECT_EQ(bla.longitude, 2.0);
  EXPECT_EQ(bla.elevation, 0.0);
}

/**************************************************************************************************/
TEST(TestGpsTools, ConstructorThreeArgs) {
  GpsTools::GpsPosition bla(1, 2, 3);

  EXPECT_EQ(bla.latitude, 1.0);
  EXPECT_EQ(bla.longitude, 2.0);
  EXPECT_EQ(bla.elevation, 3.0);
}

/**************************************************************************************************/
TEST(TestGpsTools, DistanceBearingIdentity) {
  GpsTools::GpsPosition ref(0, 0);
  GpsTools::GpsPosition tgt(0, 0);

  double distance;
  double bearing;

  distance_bearing(ref, tgt, distance, bearing);
  EXPECT_EQ(distance, 0.0);
  EXPECT_EQ(bearing, 0.0);
}

/**************************************************************************************************/
TEST(TestGpsTools, DistanceBearing) {
  GpsTools::GpsPosition ref(0, 0);
  GpsTools::GpsPosition tgt(1, 1);

  double distance;
  double bearing;

  distance_bearing(ref, tgt, distance, bearing);

  EXPECT_NEAR(distance, 156899.568, 250);
  EXPECT_NEAR(bearing, GpsTools::degrees(45, 11, 16.94), 0.2);
}

/**************************************************************************************************/
TEST(TestGpsTools, ComputePositionIdentity) {
  GpsTools::GpsPosition ref(0, 0);
  GpsTools::GpsPosition tgt;

  GpsTools::compute_from_pos_distance_bearing(ref, 0.0, 0.0, tgt);

  EXPECT_NEAR(tgt.latitude, 0, 0);
  EXPECT_NEAR(tgt.longitude, 0, 0);
}

/**************************************************************************************************/
TEST(TestGpsTools, ComputePosition) {
  GpsTools::GpsPosition ref(0, 0);
  GpsTools::GpsPosition tgt;

  GpsTools::compute_from_pos_distance_bearing(
      ref, 156899.568, GpsTools::degrees(45, 11, 16.94), tgt);

  EXPECT_NEAR(tgt.latitude, 1.0, 0.005);
  EXPECT_NEAR(tgt.longitude, 1.0, 0.002);
}
