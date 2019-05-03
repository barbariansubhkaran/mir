/*
 * AUTOGENERATED - DO NOT EDIT
 *
 * This file is generated from xdg-output-unstable-v1.xml
 * To regenerate, run the “refresh-wayland-wrapper” target.
 */

#include "xdg-output-unstable-v1_wrapper.h"

#include <boost/throw_exception.hpp>
#include <boost/exception/diagnostic_information.hpp>

#include <wayland-server-core.h>

#include "mir/log.h"

namespace mir
{
namespace wayland
{
extern struct wl_interface const wl_output_interface_data;
extern struct wl_interface const zxdg_output_manager_v1_interface_data;
extern struct wl_interface const zxdg_output_v1_interface_data;
}
}

namespace mw = mir::wayland;

namespace
{
struct wl_interface const* all_null_types [] {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr};
}

// XdgOutputManagerV1

mw::XdgOutputManagerV1* mw::XdgOutputManagerV1::from(struct wl_resource* resource)
{
    return static_cast<XdgOutputManagerV1*>(wl_resource_get_user_data(resource));
}

struct mw::XdgOutputManagerV1::Thunks
{
    static void destroy_thunk(struct wl_client* client, struct wl_resource* resource)
    {
        auto me = static_cast<XdgOutputManagerV1*>(wl_resource_get_user_data(resource));
        try
        {
            me->destroy(client, resource);
        }
        catch(...)
        {
            ::mir::log(::mir::logging::Severity::critical,
                       "frontend:Wayland",
                       std::current_exception(),
                       "Exception processing XdgOutputManagerV1::destroy() request");
        }
    }

    static void get_xdg_output_thunk(struct wl_client* client, struct wl_resource* resource, uint32_t id, struct wl_resource* output)
    {
        auto me = static_cast<XdgOutputManagerV1*>(wl_resource_get_user_data(resource));
        try
        {
            me->get_xdg_output(client, resource, id, output);
        }
        catch(...)
        {
            ::mir::log(::mir::logging::Severity::critical,
                       "frontend:Wayland",
                       std::current_exception(),
                       "Exception processing XdgOutputManagerV1::get_xdg_output() request");
        }
    }

    static void bind_thunk(struct wl_client* client, void* data, uint32_t version, uint32_t id)
    {
        auto me = static_cast<XdgOutputManagerV1*>(data);
        auto resource = wl_resource_create(client, &zxdg_output_manager_v1_interface_data,
                                           std::min(version, me->max_version), id);
        if (resource == nullptr)
        {
            wl_client_post_no_memory(client);
            BOOST_THROW_EXCEPTION((std::bad_alloc{}));
        }
        wl_resource_set_implementation(resource, Thunks::request_vtable, me, nullptr);
        try
        {
            me->bind(client, resource);
        }
        catch(...)
        {
            ::mir::log(::mir::logging::Severity::critical,
                       "frontend:Wayland",
                       std::current_exception(),
                       "Exception processing XdgOutputManagerV1::bind() request");
        }
    }

    static struct wl_interface const* get_xdg_output_types[];
    static struct wl_message const request_messages[];
    static void const* request_vtable[];
};

mw::XdgOutputManagerV1::XdgOutputManagerV1(struct wl_display* display, uint32_t max_version)
    : global{wl_global_create(display, &zxdg_output_manager_v1_interface_data, max_version, this, &Thunks::bind_thunk)},
      max_version{max_version}
{
    if (global == nullptr)
    {
        BOOST_THROW_EXCEPTION((std::runtime_error{"Failed to export zxdg_output_manager_v1 interface"}));
    }
}

mw::XdgOutputManagerV1::~XdgOutputManagerV1()
{
    wl_global_destroy(global);
}

void mw::XdgOutputManagerV1::destroy_wayland_object(struct wl_resource* resource) const
{
    wl_resource_destroy(resource);
}

struct wl_interface const* mw::XdgOutputManagerV1::Thunks::get_xdg_output_types[] {
    &zxdg_output_v1_interface_data,
    &wl_output_interface_data};

struct wl_message const mw::XdgOutputManagerV1::Thunks::request_messages[] {
    {"destroy", "", all_null_types},
    {"get_xdg_output", "no", get_xdg_output_types}};

void const* mw::XdgOutputManagerV1::Thunks::request_vtable[] {
    (void*)Thunks::destroy_thunk,
    (void*)Thunks::get_xdg_output_thunk};

// XdgOutputV1

mw::XdgOutputV1* mw::XdgOutputV1::from(struct wl_resource* resource)
{
    return static_cast<XdgOutputV1*>(wl_resource_get_user_data(resource));
}

struct mw::XdgOutputV1::Thunks
{
    static void destroy_thunk(struct wl_client*, struct wl_resource* resource)
    {
        auto me = static_cast<XdgOutputV1*>(wl_resource_get_user_data(resource));
        try
        {
            me->destroy();
        }
        catch(...)
        {
            ::mir::log(::mir::logging::Severity::critical,
                       "frontend:Wayland",
                       std::current_exception(),
                       "Exception processing XdgOutputV1::destroy() request");
        }
    }

    static void resource_destroyed_thunk(wl_resource* resource)
    {
        delete static_cast<XdgOutputV1*>(wl_resource_get_user_data(resource));
    }

    static struct wl_message const request_messages[];
    static struct wl_message const event_messages[];
    static void const* request_vtable[];
};

mw::XdgOutputV1::XdgOutputV1(struct wl_client* client, struct wl_resource* parent, uint32_t id)
    : client{client},
      resource{wl_resource_create(client, &zxdg_output_v1_interface_data, wl_resource_get_version(parent), id)}
{
    if (resource == nullptr)
    {
        wl_resource_post_no_memory(parent);
        BOOST_THROW_EXCEPTION((std::bad_alloc{}));
    }
    wl_resource_set_implementation(resource, Thunks::request_vtable, this, &Thunks::resource_destroyed_thunk);
}

void mw::XdgOutputV1::send_logical_position_event(int32_t x, int32_t y) const
{
    wl_resource_post_event(resource, Opcode::logical_position, x, y);
}

void mw::XdgOutputV1::send_logical_size_event(int32_t width, int32_t height) const
{
    wl_resource_post_event(resource, Opcode::logical_size, width, height);
}

void mw::XdgOutputV1::send_done_event() const
{
    wl_resource_post_event(resource, Opcode::done);
}

bool mw::XdgOutputV1::version_supports_name()
{
    return wl_resource_get_version(resource) >= 2;
}

void mw::XdgOutputV1::send_name_event(std::string const& name) const
{
    const char* name_resolved = name.c_str();
    wl_resource_post_event(resource, Opcode::name, name_resolved);
}

bool mw::XdgOutputV1::version_supports_description()
{
    return wl_resource_get_version(resource) >= 2;
}

void mw::XdgOutputV1::send_description_event(std::string const& description) const
{
    const char* description_resolved = description.c_str();
    wl_resource_post_event(resource, Opcode::description, description_resolved);
}

bool mw::XdgOutputV1::is_instance(wl_resource* resource)
{
    return wl_resource_instance_of(resource, &zxdg_output_v1_interface_data, Thunks::request_vtable);
}

void mw::XdgOutputV1::destroy_wayland_object() const
{
    wl_resource_destroy(resource);
}

struct wl_message const mw::XdgOutputV1::Thunks::request_messages[] {
    {"destroy", "", all_null_types}};

struct wl_message const mw::XdgOutputV1::Thunks::event_messages[] {
    {"logical_position", "ii", all_null_types},
    {"logical_size", "ii", all_null_types},
    {"done", "", all_null_types},
    {"name", "2s", all_null_types},
    {"description", "2s", all_null_types}};

void const* mw::XdgOutputV1::Thunks::request_vtable[] {
    (void*)Thunks::destroy_thunk};

namespace mir
{
namespace wayland
{

struct wl_interface const zxdg_output_manager_v1_interface_data {
    mw::XdgOutputManagerV1::interface_name,
    mw::XdgOutputManagerV1::interface_version,
    2, mw::XdgOutputManagerV1::Thunks::request_messages,
    0, nullptr};

struct wl_interface const zxdg_output_v1_interface_data {
    mw::XdgOutputV1::interface_name,
    mw::XdgOutputV1::interface_version,
    1, mw::XdgOutputV1::Thunks::request_messages,
    5, mw::XdgOutputV1::Thunks::event_messages};

}
}
