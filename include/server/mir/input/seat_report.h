/*
 * Copyright © 2016 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Brandon Schaefer <brandon.schaefer@canonical.com>
 */


#ifndef MIR_INPUT_SEAT_REPORT_H_
#define MIR_INPUT_SEAT_REPORT_H_

#include <string>
#include <vector>

class MirEvent;

namespace mir
{
namespace geometry
{
class Rectangles;
class Rectangle;
}
namespace input
{
class SeatReport
{
public:
    virtual ~SeatReport() = default;
    
    virtual void seat_add_device(uint64_t id) = 0;
    virtual void seat_remove_device(uint64_t id) = 0;
    virtual void seat_dispatch_event(MirEvent const& event) = 0;
    virtual void seat_get_rectangle_for(uint64_t id, geometry::Rectangle const& out_rect) = 0;
    virtual void seat_create_device_state() = 0;
    virtual void seat_set_key_state(uint64_t id, std::vector<uint32_t> const& scan_codes) = 0;
    virtual void seat_set_pointer_state(uint64_t id, unsigned buttons) = 0;
    virtual void seat_set_cursor_position(float cursor_x, float cursor_y) = 0;
    virtual void seat_set_confinement_region_called(geometry::Rectangles const& regions) = 0;
    virtual void seat_reset_confinement_regions() = 0;
};
}
}

#endif /* MIR_INPUT_SEAT_REPORT_H_ */
