#include <cmath>
#include <gps_tools/gps_tools.h>

using namespace GpsTools;

const double METERPERNAUTICALMILE = 1852.0;
const double NAUTICALMILESPEREGREE = 60.0;
const double RAD_PER_DEGREE = M_PI / 180.0;

/**************************************************************************************************/
double GpsTools::degrees(int degrees, double minutes) {
  return degrees + minutes / 60.0;
}

/**************************************************************************************************/
double GpsTools::degrees(int degrees, int minutes, double seconds) {
  return degrees + minutes / 60.0 + seconds / 3600.0;
}

/**************************************************************************************************/
double GpsTools::degrees2radians(double degrees) {
  return degrees * RAD_PER_DEGREE;
}

/**************************************************************************************************/
double GpsTools::radians2degrees(double radians) {
  return radians / RAD_PER_DEGREE;
}

/**************************************************************************************************/
double GpsTools::degrees2meters(double degrees) {
  return degrees * METERPERNAUTICALMILE * NAUTICALMILESPEREGREE;
}

/**************************************************************************************************/
double GpsTools::meters2degrees(double meters) {
  return meters / (METERPERNAUTICALMILE * NAUTICALMILESPEREGREE);
}

/**************************************************************************************************/
double GpsTools::normalize_relative_radians(double angle_radians) {
  // cast to <-M_PI, M_PI]
  double nrm = fmod(angle_radians, 2 * M_PI);
  if (nrm <= -M_PI) {
    nrm += 2 * M_PI;
  } else if (nrm > M_PI) {
    nrm -= 2 * M_PI;
  }
  return nrm;
}

/**************************************************************************************************/
double GpsTools::normalize_absolute_radians(double angle_radians) {
  // cast to [0, 2*M_PI>
  double nrm = fmod(angle_radians, 2 * M_PI);
  if (nrm < 0) {
    nrm += 2 * M_PI;
  }
  return nrm;
}

/**************************************************************************************************/
void GpsTools::distance_bearing(GpsPosition reference, GpsPosition target,
                                double &distance_meters,
                                double &bearing_degrees) {
  const double lat_factor =
      cos(degrees2radians(reference.latitude + target.latitude) / 2.0);
  const double dlat = (target.latitude - reference.latitude);
  const double dlon = (target.longitude - reference.longitude);
  const double dy = degrees2meters(dlat);
  const double dx = degrees2meters(dlon) * lat_factor;

  distance_meters = sqrt(dx * dx + dy * dy);
  bearing_degrees = radians2degrees(normalize_absolute_radians(atan2(dx, dy)));
}

/**************************************************************************************************/
void GpsTools::compute_from_pos_distance_bearing(GpsPosition reference,
                                                 double distance,
                                                 double bearing,
                                                 GpsPosition &target) {
  const double lat_factor = cos(degrees2radians(reference.latitude));
  const double dlon =
      distance / degrees2meters(1) * sin(degrees2radians(bearing)) / lat_factor;
  const double dlat =
      distance / degrees2meters(1) * cos(degrees2radians(bearing));

  target.longitude = reference.longitude + dlon;
  target.latitude = reference.latitude + dlat;
}
