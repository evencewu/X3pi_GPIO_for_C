#ifndef __GPIO_40PIN_H__
#define __GPIO_40PIN_H__

#include "rclcpp/rclcpp.hpp"
#include <iostream>
#include <memory>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <time.h>


#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>


#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define MAX_BUF	64
#define RET_OK 0

class gpio_40pin
{
    public:
        gpio_40pin();
        void gpio_init(int board_num);

        void gpio_set_dir(int out_flag);
        void gpio_export();
        void gpio_unexport(); 

        void gpio_set_value(int value);    
        void gpio_get_value();   
        void gpio_set_edge(); 

        void gpio_pwm(int frequency_,float Duty_ratio_); 
        void pwm_back();   

    private:
        boost::asio::io_service io_;
        boost::asio::deadline_timer timer_;

        bool state;
        int gpio;

        int value_fd;
        int len;
        char direction_buf[MAX_BUF];
        char value_buf[MAX_BUF];

        int frequency;
        float Duty_ratio;

        int high_time;
        int low_time;
};

#endif
