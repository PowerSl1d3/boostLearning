#include <iostream>
#include <boost/program_options.hpp>

int main(int argc, char* argv[]) {

   namespace opt = boost::program_options;

   opt::options_description desc("All options");

   desc.add_options()
   ("apples,a", opt::value<int>()->default_value(10), "How many apples do you have")
   ("oranges,o", opt::value<int>()->required(), "How many oranges do you have")
   ("help,h", "Produce help message");

   opt::variables_map vm;

   opt::store(opt::parse_command_line(argc, argv, desc), vm);

   /*try {

      opt::store(opt::parse_config_file<char>("apples_oranges.cfg", desc), vm);

   } catch (const opt::reading_file& e) {

      std::cerr << e.what() << std::endl;
      return 2;

   }*/

   try {
      opt::notify(vm);
   } catch (const opt::required_option& e) {

      std::cerr << e.what() << std::endl;
      return 2;

   }

   if (vm.count("help")) {

      std::cout << desc << std::endl;
      return 1;

   }

   std::cout << "Fruits count: " << vm["apples"].as<int>() + vm["oranges"].as<int>() << std::endl;

   return 0;
}
