#include "quad_utils/trajectory_publisher.hpp"
#include "quad_utils/terrain_map_publisher.hpp"
#include "quad_utils/rviz_interface_node.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  // You MUST use the MultiThreadedExecutor to use, well, multiple threads
  rclcpp::executors::MultiThreadedExecutor executor;
  // auto trajectory = std::make_shared<ros2_quadruped::quad_utils::TrajectoryPublisher>();
  auto terrain_map = std::make_shared<ros2_quadruped::quad_utils::TerrainMapPublisher>();
  auto rviz_show = std::make_shared<ros2_quadruped::quad_utils::RVIZPublisher>(); 
       
  // executor.add_node(trajectory);
  executor.add_node(terrain_map);
  executor.add_node(rviz_show);
  executor.spin();
  rclcpp::shutdown();
  return 0;
}
