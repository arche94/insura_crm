#pragma once

#include "managers/InteractionManager.hpp"

namespace insura_ui::interaction_ui {
extern InteractionManager* interaction_manager;

void list();
void add();
void search();
}  // namespace insura_ui::interaction_ui