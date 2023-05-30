#include <rclcpp/rclcpp.hpp>
#include <QApplication>
#include <QUiLoader>
#include <QFile>
#include <QWidget>
#include <QPushButton>
//#include <ament_index_cpp/get_package_share_directory.hpp>
#include <std_msgs/msg/string.hpp>

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  QApplication app(argc, argv);

  // Load the UI file using QUiLoader
  QUiLoader loader;
  QFile file("../ui/untitled.ui");
  file.open(QFile::ReadOnly);
  QWidget *window = loader.load(&file);
  file.close();

  auto node = rclcpp::Node::make_shared("my_node");
  auto publisher = node->create_publisher<std_msgs::msg::String>("topic", 10);

  // Assuming there's a QPushButton in your UI file with the objectName "myButton"
  QPushButton *button = window->findChild<QPushButton*>("pushButton");
  if (button != nullptr) {
    QObject::connect(button, &QPushButton::clicked, [&]() {
        auto message = std_msgs::msg::String();
        message.data = "Hello, ROS2!";
        publisher->publish(message);
    });
  }

  window->show();

  std::thread([&]() {
      rclcpp::spin(node);
  }).detach();

  return app.exec();
}

