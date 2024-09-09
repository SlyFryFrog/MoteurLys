#pragma once

// For use by Lys applications

#include "Lys/debug/fps.hpp"
#include "Lys/debug/logging.hpp"

#include "Lys/core/utils/constants.hpp"
#include "Lys/core/utils/paths.hpp"

#include "Lys/scene/nodes/2d/camera_2d.hpp"
#include "Lys/scene/nodes/2d/node_2d.hpp"
#include "Lys/scene/nodes/2d/sprite_2d.hpp"
#include "Lys/scene/nodes/3d/camera_3d.hpp"
#include "Lys/scene/nodes/3d/node_3d.hpp"
#include "Lys/scene/nodes/core/node.hpp"
#include "Lys/scene/nodes/ui/label.hpp"
#include "Lys/scene/nodes/ui/widget.hpp"

#include "Lys/core/input/input_manager.hpp"
#include "Lys/core/input/input_events.hpp"
#include "Lys/core/io/image.hpp"
#include "Lys/core/math/vector3.hpp"
#include "Lys/core/utils/paths.hpp"

// Renderer

#include "Lys/renderer/core/window.hpp"
#include "Lys/renderer/core/renderer.hpp"

#ifdef OPENGL
#include "Lys/renderer/OpenGL/binding/vertex_array.hpp"
#include "Lys/renderer/OpenGL/binding/vertex_buffer.hpp"
#include "Lys/renderer/OpenGL/shaders/shader_program.hpp"
#include "Lys/renderer/OpenGL/texture.hpp"
#include "Lys/renderer/OpenGL/utils/debug.hpp"
#include "Lys/renderer/OpenGL/vertex.hpp"
#elif VULKAN
#error Vulkan is not yet supported, please use the flag -DOPENGL.
#endif
// End renderer