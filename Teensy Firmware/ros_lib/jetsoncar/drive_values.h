#ifndef _ROS_jetsoncar_drive_values_h
#define _ROS_jetsoncar_drive_values_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jetsoncar
{

  class drive_values : public ros::Msg
  {
    public:
      int16_t pwm_drive;
      int16_t pwm_angle;

    drive_values():
      pwm_drive(0),
      pwm_angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_pwm_drive;
      u_pwm_drive.real = this->pwm_drive;
      *(outbuffer + offset + 0) = (u_pwm_drive.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pwm_drive.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pwm_drive);
      union {
        int16_t real;
        uint16_t base;
      } u_pwm_angle;
      u_pwm_angle.real = this->pwm_angle;
      *(outbuffer + offset + 0) = (u_pwm_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pwm_angle.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pwm_angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_pwm_drive;
      u_pwm_drive.base = 0;
      u_pwm_drive.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pwm_drive.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pwm_drive = u_pwm_drive.real;
      offset += sizeof(this->pwm_drive);
      union {
        int16_t real;
        uint16_t base;
      } u_pwm_angle;
      u_pwm_angle.base = 0;
      u_pwm_angle.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pwm_angle.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pwm_angle = u_pwm_angle.real;
      offset += sizeof(this->pwm_angle);
     return offset;
    }

    const char * getType(){ return "jetsoncar/drive_values"; };
    const char * getMD5(){ return "180768e2d6cce7b3f71749adb84f7b29"; };

  };

}
#endif