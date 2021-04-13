
#ifndef PROXYFMU_PROCESS_HELPER_HPP
#define PROXYFMU_PROCESS_HELPER_HPP

#include <proxyfmu/fs_portability.hpp>

#include <iostream>

namespace proxyfmu
{

void start_process(const proxyfmu::filesystem::path& fmuPath, const std::string& instanceName, const int port)
{
    std::string cmd(
        "proxy_server"
        " --port " +
        std::to_string(port) +
        " --fmu \"" + fmuPath.string() + +"\""
                                          " --instanceName " +
        instanceName);
    auto status = system(cmd.c_str());
    std::cout << "[proxyfmu] External proxy process for instance '" << instanceName << "' returned with status " << std::to_string(status) << std::endl;
}

} // namespace proxyfmu

#endif //PROXYFMU_PROCESS_HELPER_HPP
