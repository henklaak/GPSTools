#ifndef GPS_TOOLS_GPS_TOOLS_H
#define GPS_TOOLS_GPS_TOOLS_H

namespace GpsTools {

struct GpsPosition {
  double latitude = 0.0;  // degrees North
  double longitude = 0.0; // degrees East
  double elevation = 0.0; // meters above WGS-84
};

double degrees(int degrees, double minutes);
double degrees(int degrees, int minutes, double seconds);

double degrees2radians(double degrees);
double radians2degrees(double radians);
double degrees2meters(double degrees);
double meters2degrees(double meters);

double normalize_relative_radians(double angle_radians);
double normalize_absolute_radians(double angle_radians);

void distance_bearing(GpsPosition reference, GpsPosition target,
                      double &distance_meters, double &bearing_degrees);
void compute_from_pos_distance_bearing(GpsPosition reference, double distance,
                                       double bearing, GpsPosition &target);

} // namespace GpsTools

#endif
