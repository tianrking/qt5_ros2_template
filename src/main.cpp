#include <rclcpp/rclcpp.hpp>
#include <QApplication>
#include <QPushButton>
#include <std_msgs/msg/string.hpp>

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  QApplication app(argc, argv);

  QPushButton button("Hello, ROS2 with Qt5!");

  auto node = rclcpp::Node::make_shared("my_node");
  auto publisher = node->create_publisher<std_msgs::msg::String>("topic", 10);

  QObject::connect(&button, &QPushButton::clicked, [&]() {
      auto message = std_msgs::msg::String();
      message.data = "Hello, ROS2!";
      publisher->publish(message);
  });

  button.show();

  std::thread([&]() {
      rclcpp::spin(node);
  }).detach();

  return app.exec();
}

