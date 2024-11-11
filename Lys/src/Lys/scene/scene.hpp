#include <fstream>
#include <string>
#include <Lys/debug/logging.hpp>

namespace Lys
{
	class Scene
	{
        std::string id;

	public:
        Scene(const std::string &path);
        ~Scene();

		void load_lys(const std::string &lys) 
        {
            std::ifstream file(lys);        
            if (!file.is_open()) 
            {
                LYS_CRITICAL("Could not load the scene file ", lys);
            }
    
            std::string line;
            while (std::getline(file, line)) 
            {
                for(char c : line)
                {
                    if (c == '#')
                    {
                        break;
                    }
                    
                }
            }

            file.close();  // Close the file
        }

	private:
        void parse_node()
        {

        }

        void parse_ext_rsc() 
        {
        
        }

        void generate_id(); 
	};
} // namespace Lys
