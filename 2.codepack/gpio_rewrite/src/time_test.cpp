#include "rclcpp/rclcpp.hpp"
#include <iostream>
#include "gpio_rewrite/gpio_40pin.h"
#include <unistd.h>

int main(int argc, char **argv)
{
	rclcpp::init(argc, argv);
    
    gpio_40pin GPIO37;

	GPIO37.gpio_init(105);
	GPIO37.gpio_export();
	GPIO37.gpio_set_dir(1);

	GPIO37.gpio_pwm(3000 , 0.2);

    
	GPIO37.gpio_unexport();
    rclcpp::shutdown();
	return 0;
}