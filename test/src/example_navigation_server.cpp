/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "example_navigation_server.h"

#include <godot_cpp/core/class_db.hpp>

void ExampleNavigationServer::_bind_methods() {
}

TypedArray<RID> ExampleNavigationServer::_get_maps() const {
	_log_invocation(__FUNCTION__);

	List<RID> map_rids;
	map_owner.get_owned_list(&map_rids);

	TypedArray<RID> maps;
	for (RID rid : map_rids) {
		maps.push_back(rid);
	}

	return maps;
}

RID ExampleNavigationServer::_map_create() {
	_log_invocation(__FUNCTION__);

	return map_owner.make_rid();
}

void ExampleNavigationServer::_map_set_active(const RID &map, bool active) {
	_log_invocation(__FUNCTION__, map, active);

	NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND(nav_map == nullptr);

	nav_map->active = active;
}

bool ExampleNavigationServer::_map_is_active(const RID &map) const {
	_log_invocation(__FUNCTION__, map);

	const NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND_V(nav_map == nullptr, false);

	return nav_map->active;
}

void ExampleNavigationServer::_map_set_up(const RID &map, const Vector3 &up) {
	_log_invocation(__FUNCTION__, map, up);

	NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND(nav_map == nullptr);

	nav_map->up_vector = up;
}

Vector3 ExampleNavigationServer::_map_get_up(const RID &map) const {
	_log_invocation(__FUNCTION__, map);

	const NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND_V(nav_map == nullptr, Vector3());

	return nav_map->up_vector;
}

void ExampleNavigationServer::_map_set_cell_size(const RID &map, double cell_size) {
	_log_invocation(__FUNCTION__, map, cell_size);

	NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND(nav_map == nullptr);

	nav_map->cell_size = cell_size;
}

double ExampleNavigationServer::_map_get_cell_size(const RID &map) const {
	_log_invocation(__FUNCTION__, map);

	const NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND_V(nav_map == nullptr, 0.0);

	return nav_map->cell_size;
}

void ExampleNavigationServer::_map_set_edge_connection_margin(const RID &map, double margin) {
	_log_invocation(__FUNCTION__, map, margin);

	NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND(nav_map == nullptr);

	nav_map->edge_connection_margin = margin;
}

double ExampleNavigationServer::_map_get_edge_connection_margin(const RID &map) const {
	_log_invocation(__FUNCTION__, map);

	const NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND_V(nav_map == nullptr, 0.0);

	return nav_map->edge_connection_margin;
}

void ExampleNavigationServer::_map_set_link_connection_radius(const RID &map, double radius) {
	_log_invocation(__FUNCTION__, map, radius);

	NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND(nav_map == nullptr);

	nav_map->link_connection_radius = radius;
}

double ExampleNavigationServer::_map_get_link_connection_radius(const RID &map) const {
	_log_invocation(__FUNCTION__, map);

	const NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND_V(nav_map == nullptr, 0.0);

	return nav_map->link_connection_radius;
}

PackedVector3Array ExampleNavigationServer::_map_get_path(const RID &map, const Vector3 &origin, const Vector3 &destination, bool optimize, int64_t navigation_layers) const {
	_log_invocation(__FUNCTION__, origin, destination, optimize, navigation_layers);

	return PackedVector3Array();
}

Vector3 ExampleNavigationServer::_map_get_closest_point_to_segment(const RID &map, const Vector3 &start, const Vector3 &end, bool use_collision) const {
	_log_invocation(__FUNCTION__, start, end, use_collision);

	return Vector3();
}

Vector3 ExampleNavigationServer::_map_get_closest_point(const RID &map, const Vector3 &to_point) const {
	_log_invocation(__FUNCTION__, to_point);

	return Vector3();
}

Vector3 ExampleNavigationServer::_map_get_closest_point_normal(const RID &map, const Vector3 &to_point) const {
	_log_invocation(__FUNCTION__, to_point);

	return Vector3();
}

RID ExampleNavigationServer::_map_get_closest_point_owner(const RID &map, const Vector3 &to_point) const {
	_log_invocation(__FUNCTION__, to_point);

	return RID();
}

TypedArray<RID> ExampleNavigationServer::_map_get_links(const RID &map) const {
	_log_invocation(__FUNCTION__, map);

	const NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND_V(nav_map == nullptr, TypedArray<RID>());

	TypedArray<RID> links;
	for (RID link : nav_map->links) {
		links.push_back(link);
	}
	return links;
}

TypedArray<RID> ExampleNavigationServer::_map_get_regions(const RID &map) const {
	_log_invocation(__FUNCTION__, map);

	const NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND_V(nav_map == nullptr, TypedArray<RID>());

	TypedArray<RID> regions;
	for (RID region : nav_map->regions) {
		regions.push_back(region);
	}
	return regions;
}

TypedArray<RID> ExampleNavigationServer::_map_get_agents(const RID &map) const {
	_log_invocation(__FUNCTION__, map);

	const NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND_V(nav_map == nullptr, TypedArray<RID>());

	TypedArray<RID> agents;
	for (RID agent : nav_map->agents) {
		agents.push_back(agent);
	}
	return agents;
}

void ExampleNavigationServer::_map_force_update(const RID &map) {
	_log_invocation(__FUNCTION__, map);
}

void ExampleNavigationServer::_query_path_extension(const NavigationServer3DExtensionPathQueryParameters *parameters, NavigationServer3DExtensionPathQueryResult *result) const {
	_log_invocation(__FUNCTION__);
}

RID ExampleNavigationServer::_region_create() {
	_log_invocation(__FUNCTION__);

	return region_owner.make_rid();
}

void ExampleNavigationServer::_region_set_enter_cost(const RID &region, double enter_cost) {
	_log_invocation(__FUNCTION__, region, enter_cost);

	NavRegion *nav_region = region_owner.get_or_null(region);
	ERR_FAIL_COND(nav_region == nullptr);

	nav_region->enter_cost = enter_cost;
}

double ExampleNavigationServer::_region_get_enter_cost(const RID &region) const {
	_log_invocation(__FUNCTION__, region);

	const NavRegion *nav_region = region_owner.get_or_null(region);
	ERR_FAIL_COND_V(nav_region == nullptr, 0.0);

	return nav_region->enter_cost;
}

void ExampleNavigationServer::_region_set_travel_cost(const RID &region, double travel_cost) {
	_log_invocation(__FUNCTION__, region, travel_cost);

	NavRegion *nav_region = region_owner.get_or_null(region);
	ERR_FAIL_COND(nav_region == nullptr);

	nav_region->travel_cost = travel_cost;
}

double ExampleNavigationServer::_region_get_travel_cost(const RID &region) const {
	_log_invocation(__FUNCTION__, region);

	const NavRegion *nav_region = region_owner.get_or_null(region);
	ERR_FAIL_COND_V(nav_region == nullptr, 0.0);

	return nav_region->travel_cost;
}

void ExampleNavigationServer::_region_set_owner_id(const RID &region, int64_t owner_id) {
	_log_invocation(__FUNCTION__, region, owner_id);

	NavRegion *nav_region = region_owner.get_or_null(region);
	ERR_FAIL_COND(nav_region == nullptr);

	nav_region->owner_id = owner_id;
}

int64_t ExampleNavigationServer::_region_get_owner_id(const RID &region) const {
	_log_invocation(__FUNCTION__, region);

	const NavRegion *nav_region = region_owner.get_or_null(region);
	ERR_FAIL_COND_V(nav_region == nullptr, 0);

	return nav_region->owner_id;
}

bool ExampleNavigationServer::_region_owns_point(const RID &region, const Vector3 &point) const {
	_log_invocation(__FUNCTION__, point);

	return false;
}

void ExampleNavigationServer::_region_set_map(const RID &region, const RID &map) {
	_log_invocation(__FUNCTION__, region, map);

	NavRegion *nav_region = region_owner.get_or_null(region);
	ERR_FAIL_COND(nav_region == nullptr);

	NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND(nav_map == nullptr);

	NavMap *old_nav_map = map_owner.get_or_null(nav_region->map);
	if (old_nav_map != nullptr) {
		old_nav_map->regions.erase(region);
	}

	nav_region->map = map;
	nav_map->regions.push_back(region);
}

RID ExampleNavigationServer::_region_get_map(const RID &region) const {
	_log_invocation(__FUNCTION__, region);

	const NavRegion *nav_region = region_owner.get_or_null(region);
	ERR_FAIL_COND_V(nav_region == nullptr, RID());

	return nav_region->map;
}

void ExampleNavigationServer::_region_set_navigation_layers(const RID &region, int64_t navigation_layers) {
	_log_invocation(__FUNCTION__, region, navigation_layers);

	NavRegion *nav_region = region_owner.get_or_null(region);
	ERR_FAIL_COND(nav_region == nullptr);

	nav_region->navigation_layers = navigation_layers;
}

int64_t ExampleNavigationServer::_region_get_navigation_layers(const RID &region) const {
	_log_invocation(__FUNCTION__, region);

	const NavRegion *nav_region = region_owner.get_or_null(region);
	ERR_FAIL_COND_V(nav_region == nullptr, 0);

	return nav_region->navigation_layers;
}

void ExampleNavigationServer::_region_set_transform(const RID &region, const Transform3D &transform) {
	_log_invocation(__FUNCTION__, region, transform);

	NavRegion *nav_region = region_owner.get_or_null(region);
	ERR_FAIL_COND(nav_region == nullptr);

	nav_region->transform = transform;
}

void ExampleNavigationServer::_region_set_navigation_mesh(const RID &region, const Ref<NavigationMesh> &navigation_mesh) {
	_log_invocation(__FUNCTION__, region, navigation_mesh);

	NavRegion *nav_region = region_owner.get_or_null(region);
	ERR_FAIL_COND(nav_region == nullptr);

	nav_region->navigation_mesh = navigation_mesh;
}

void ExampleNavigationServer::_region_bake_navigation_mesh(const Ref<NavigationMesh> &navigation_mesh, Node *root_node) {
	_log_invocation(__FUNCTION__, navigation_mesh, root_node);
}

int64_t ExampleNavigationServer::_region_get_connections_count(const RID &region) const {
	_log_invocation(__FUNCTION__, region);

	return 0;
}

Vector3 ExampleNavigationServer::_region_get_connection_pathway_start(const RID &region, int64_t connection) const {
	_log_invocation(__FUNCTION__, region, connection);

	return Vector3();
}

Vector3 ExampleNavigationServer::_region_get_connection_pathway_end(const RID &region, int64_t connection) const {
	_log_invocation(__FUNCTION__, region, connection);

	return Vector3();
}

RID ExampleNavigationServer::_link_create() {
	_log_invocation(__FUNCTION__);

	return link_owner.make_rid();
}

void ExampleNavigationServer::_link_set_map(const RID &link, const RID &map) {
	_log_invocation(__FUNCTION__, link, map);

	NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND(nav_link == nullptr);

	NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND(nav_map == nullptr);

	NavMap *old_nav_map = map_owner.get_or_null(nav_link->map);
	if (old_nav_map != nullptr) {
		old_nav_map->links.erase(link);
	}

	nav_link->map = map;
	nav_map->links.push_back(link);
}

RID ExampleNavigationServer::_link_get_map(const RID &link) const {
	_log_invocation(__FUNCTION__, link);

	const NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND_V(nav_link == nullptr, RID());

	return nav_link->map;
}

void ExampleNavigationServer::_link_set_bidirectional(const RID &link, bool bidirectional) {
	_log_invocation(__FUNCTION__, link, bidirectional);

	NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND(nav_link == nullptr);

	nav_link->bidirectional = bidirectional;
}

bool ExampleNavigationServer::_link_is_bidirectional(const RID &link) const {
	_log_invocation(__FUNCTION__, link);

	const NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND_V(nav_link == nullptr, false);

	return nav_link->bidirectional;
}

void ExampleNavigationServer::_link_set_navigation_layers(const RID &link, int64_t navigation_layers) {
	_log_invocation(__FUNCTION__, link, navigation_layers);

	NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND(nav_link == nullptr);

	nav_link->navigation_layers = navigation_layers;
}

int64_t ExampleNavigationServer::_link_get_navigation_layers(const RID &link) const {
	_log_invocation(__FUNCTION__, link);

	const NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND_V(nav_link == nullptr, 0);

	return nav_link->navigation_layers;
}

void ExampleNavigationServer::_link_set_start_location(const RID &link, const Vector3 &location) {
	_log_invocation(__FUNCTION__, link, location);

	NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND(nav_link == nullptr);

	nav_link->start_location = location;
}

Vector3 ExampleNavigationServer::_link_get_start_location(const RID &link) const {
	_log_invocation(__FUNCTION__, link);

	const NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND_V(nav_link == nullptr, Vector3());

	return nav_link->start_location;
}

void ExampleNavigationServer::_link_set_end_location(const RID &link, const Vector3 &location) {
	_log_invocation(__FUNCTION__, link, location);

	NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND(nav_link == nullptr);

	nav_link->end_location = location;
}

Vector3 ExampleNavigationServer::_link_get_end_location(const RID &link) const {
	_log_invocation(__FUNCTION__, link);

	const NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND_V(nav_link == nullptr, Vector3());

	return nav_link->end_location;
}

void ExampleNavigationServer::_link_set_enter_cost(const RID &link, double enter_cost) {
	_log_invocation(__FUNCTION__, link, enter_cost);

	NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND(nav_link == nullptr);

	nav_link->enter_cost = enter_cost;
}

double ExampleNavigationServer::_link_get_enter_cost(const RID &link) const {
	_log_invocation(__FUNCTION__, link);

	const NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND_V(nav_link == nullptr, 0.0);

	return nav_link->enter_cost;
}

void ExampleNavigationServer::_link_set_travel_cost(const RID &link, double travel_cost) {
	_log_invocation(__FUNCTION__, link, travel_cost);

	NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND(nav_link == nullptr);

	nav_link->travel_cost = travel_cost;
}

double ExampleNavigationServer::_link_get_travel_cost(const RID &link) const {
	_log_invocation(__FUNCTION__, link);

	const NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND_V(nav_link == nullptr, 0.0);

	return nav_link->travel_cost;
}

void ExampleNavigationServer::_link_set_owner_id(const RID &link, int64_t owner_id) {
	_log_invocation(__FUNCTION__, link, owner_id);

	NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND(nav_link == nullptr);

	nav_link->owner_id = owner_id;
}

int64_t ExampleNavigationServer::_link_get_owner_id(const RID &link) const {
	_log_invocation(__FUNCTION__, link);

	const NavLink *nav_link = link_owner.get_or_null(link);
	ERR_FAIL_COND_V(nav_link == nullptr, 0);

	return nav_link->owner_id;
}

RID ExampleNavigationServer::_agent_create() {
	_log_invocation(__FUNCTION__);

	return agent_owner.make_rid();
}

void ExampleNavigationServer::_agent_set_map(const RID &agent, const RID &map) {
	_log_invocation(__FUNCTION__, agent, map);

	NavAgent *nav_agent = agent_owner.get_or_null(agent);
	ERR_FAIL_COND(nav_agent == nullptr);

	NavMap *nav_map = map_owner.get_or_null(map);
	ERR_FAIL_COND(nav_map == nullptr);

	NavMap *old_nav_map = map_owner.get_or_null(nav_agent->map);
	if (old_nav_map != nullptr) {
		old_nav_map->agents.erase(agent);
	}

	nav_agent->map = map;
	nav_map->agents.push_back(agent);
}

RID ExampleNavigationServer::_agent_get_map(const RID &agent) const {
	_log_invocation(__FUNCTION__, agent);

	const NavAgent *nav_agent = agent_owner.get_or_null(agent);
	ERR_FAIL_COND_V(nav_agent == nullptr, RID());

	return nav_agent->map;
}

void ExampleNavigationServer::_agent_set_neighbor_distance(const RID &agent, double distance) {
	_log_invocation(__FUNCTION__, agent, distance);

	NavAgent *nav_agent = agent_owner.get_or_null(agent);
	ERR_FAIL_COND(nav_agent == nullptr);

	nav_agent->neighbor_distance = distance;
}

void ExampleNavigationServer::_agent_set_max_neighbors(const RID &agent, int64_t count) {
	_log_invocation(__FUNCTION__, agent, count);

	NavAgent *nav_agent = agent_owner.get_or_null(agent);
	ERR_FAIL_COND(nav_agent == nullptr);

	nav_agent->max_neighbors = count;
}

void ExampleNavigationServer::_agent_set_time_horizon(const RID &agent, double time) {
	_log_invocation(__FUNCTION__, agent, time);

	NavAgent *nav_agent = agent_owner.get_or_null(agent);
	ERR_FAIL_COND(nav_agent == nullptr);

	nav_agent->time_horizon = time;
}

void ExampleNavigationServer::_agent_set_radius(const RID &agent, double radius) {
	_log_invocation(__FUNCTION__, agent, radius);

	NavAgent *nav_agent = agent_owner.get_or_null(agent);
	ERR_FAIL_COND(nav_agent == nullptr);

	nav_agent->radius = radius;
}

void ExampleNavigationServer::_agent_set_max_speed(const RID &agent, double max_speed) {
	_log_invocation(__FUNCTION__, agent, max_speed);

	NavAgent *nav_agent = agent_owner.get_or_null(agent);
	ERR_FAIL_COND(nav_agent == nullptr);

	nav_agent->max_speed = max_speed;
}

void ExampleNavigationServer::_agent_set_velocity(const RID &agent, const Vector3 &velocity) {
	_log_invocation(__FUNCTION__, agent, velocity);

	NavAgent *nav_agent = agent_owner.get_or_null(agent);
	ERR_FAIL_COND(nav_agent == nullptr);

	nav_agent->velocity = velocity;
}

void ExampleNavigationServer::_agent_set_target_velocity(const RID &agent, const Vector3 &target_velocity) {
	_log_invocation(__FUNCTION__, agent, target_velocity);

	NavAgent *nav_agent = agent_owner.get_or_null(agent);
	ERR_FAIL_COND(nav_agent == nullptr);

	nav_agent->target_velocity = target_velocity;
}

void ExampleNavigationServer::_agent_set_position(const RID &agent, const Vector3 &position) {
	_log_invocation(__FUNCTION__, agent, position);

	NavAgent *nav_agent = agent_owner.get_or_null(agent);
	ERR_FAIL_COND(nav_agent == nullptr);

	nav_agent->position = position;
}

void ExampleNavigationServer::_agent_set_ignore_y(const RID &agent, bool ignore_y) {
	_log_invocation(__FUNCTION__, agent, ignore_y);

	NavAgent *nav_agent = agent_owner.get_or_null(agent);
	ERR_FAIL_COND(nav_agent == nullptr);

	nav_agent->ignore_y = ignore_y;
}

bool ExampleNavigationServer::_agent_is_map_changed(const RID &agent) const {
	_log_invocation(__FUNCTION__, agent);

	return false;
}

void ExampleNavigationServer::_agent_set_callback(const RID &agent, int64_t object_id, const StringName &method, const Variant &userdata) {
	_log_invocation(__FUNCTION__, agent, object_id, method, userdata);

	NavAgent *nav_agent = agent_owner.get_or_null(agent);
	ERR_FAIL_COND(nav_agent == nullptr);

	nav_agent->callback = Callable(ObjectDB::get_instance(object_id), method);
}

void ExampleNavigationServer::_free(const RID &rid) {
	_log_invocation(__FUNCTION__, rid);

	if (agent_owner.owns(rid)) {
		NavAgent *nav_agent = agent_owner.get_or_null(rid);
		ERR_FAIL_COND(nav_agent == nullptr);

		NavMap *nav_map = map_owner.get_or_null(nav_agent->map);
		if (nav_map != nullptr) {
			nav_map->agents.erase(rid);
		}

		agent_owner.free(rid);
	} else if (region_owner.owns(rid)) {
		NavRegion *nav_region = region_owner.get_or_null(rid);
		ERR_FAIL_COND(nav_region == nullptr);

		NavMap *nav_map = map_owner.get_or_null(nav_region->map);
		if (nav_map != nullptr) {
			nav_map->regions.erase(rid);
		}

		region_owner.free(rid);
	} else if (link_owner.owns(rid)) {
		NavLink *nav_link = link_owner.get_or_null(rid);
		ERR_FAIL_COND(nav_link == nullptr);

		NavMap *nav_map = map_owner.get_or_null(nav_link->map);
		if (nav_map != nullptr) {
			nav_map->links.erase(rid);
		}

		link_owner.free(rid);
	} else if (map_owner.owns(rid)) {
		map_owner.free(rid);
	}
}

void ExampleNavigationServer::_set_active(bool active) {
	_log_invocation(__FUNCTION__, active);
}

void ExampleNavigationServer::_process(double delta_time) {
	//UtilityFunctions::print_verbose(__FUNCTION__, "(", delta_time, ")");
}

/////////////////////////

void ExampleNavigationServerFactory::_bind_methods() {
	ClassDB::bind_method(D_METHOD("create_server"), &ExampleNavigationServerFactory::create_server);
}
