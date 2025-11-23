#pragma once

#include "TaskManager.h"

namespace taskmgr::ui {

class ConsoleUI {
public:
    static void run(taskmgr::TaskManager& manager);
};

} // namespace taskmgr::ui
