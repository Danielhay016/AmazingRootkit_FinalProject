#include "Task.h"

Task * Task::BuildTask(const std::string & module_name, const json & args)
{
    std::cout << "BuildTask with args:" << args.dump() << std::endl;

    supported_modules sm = BaseModule::supported_module_for_name(module_name);
    
    if(sm == supported_modules::NUM_OF_MODULES)
    {
        throw std::runtime_error("Invalid Module");
    }
    
    BaseModule * module_derived = nullptr;
    
    switch (sm)
    {
    case supported_modules::FILE_GRABBER:
        module_derived = new FileGrabber(module_name, args);
        break;
    case supported_modules::SCREEN_SHOOTER:
        module_derived = new Screenshot(module_name, args);
        break;
    
    default:
        break;
    }

    return new Task(module_derived);
} 

bool Task::operator==(Task * t2)
{
    return get_task_type() == t2->get_task_type();
}
