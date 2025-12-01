#include "rclcpp/rclcpp.hpp"

class MyNode : public rclcpp::Node 
{
public:
    MyNode() : Node("cpp_test"), counter(0)
    {
        RCLCPP_INFO(this->get_logger(), "Hello, world");
        timer = this->create_wall_timer(
            std::chrono::seconds(1),
            [this]() { timerCallback(); });
    }
    
private:
    void timerCallback()
    {
        RCLCPP_INFO(this->get_logger(), "Hello00000000, %d", counter);
        counter++;
    }
    rclcpp::TimerBase::SharedPtr timer;
    int counter;

};

int main(int argc, char** argv) 
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<MyNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
