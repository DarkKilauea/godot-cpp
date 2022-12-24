/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#ifndef EXAMPLE_NAVIGATION_SERVER_H
#define EXAMPLE_NAVIGATION_SERVER_H

#include <godot_cpp/classes/navigation_server3d_extension.hpp>

#include <godot_cpp/classes/navigation_mesh.hpp>
#include <godot_cpp/classes/navigation_server3d_extension_path_query_parameters.hpp>
#include <godot_cpp/classes/navigation_server3d_extension_path_query_result.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/templates/rid_owner.hpp>
#include <godot_cpp/variant/rid.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/vector3.hpp>

using namespace godot;

class ExampleNavigationServer : public NavigationServer3DExtension {
	GDCLASS(ExampleNavigationServer, NavigationServer3DExtension);

	struct NavRegion {
		double enter_cost;
		double travel_cost;
		int64_t owner_id;
		RID map;
		int64_t navigation_layers;
		Transform3D transform;
		Ref<NavigationMesh> navigation_mesh;
	};

	struct NavLink {
		RID map;
		bool bidirectional;
		int64_t navigation_layers;
		Vector3 start_location;
		Vector3 end_location;
		double enter_cost;
		double travel_cost;
		int64_t owner_id;
	};

	struct NavAgent {
		RID map;
		double neighbor_distance;
		int64_t max_neighbors;
		double time_horizon;
		double radius;
		double max_speed;
		Vector3 velocity;
		Vector3 target_velocity;
		Vector3 position;
		bool ignore_y;
		Callable callback;
	};

	struct NavMap {
		bool active;
		Vector3 up_vector;
		double cell_size;
		double edge_connection_margin;
		double link_connection_radius;

		List<RID> regions;
		List<RID> links;
		List<RID> agents;
	};

	mutable RID_Owner<NavMap> map_owner;
	mutable RID_Owner<NavRegion> region_owner;
	mutable RID_Owner<NavLink> link_owner;
	mutable RID_Owner<NavAgent> agent_owner;

	template <class... Args>
	static void _log_invocation(const String &method_name, const Args &...args) {
		UtilityFunctions::print(method_name, "(", args..., ")");
	}

protected:
	static void _bind_methods();

public:
	TypedArray<RID> _get_maps() const override;
	RID _map_create() override;
	void _map_set_active(const RID &map, bool active) override;
	bool _map_is_active(const RID &map) const override;
	void _map_set_up(const RID &map, const Vector3 &up) override;
	Vector3 _map_get_up(const RID &map) const override;
	void _map_set_cell_size(const RID &map, double cell_size) override;
	double _map_get_cell_size(const RID &map) const override;
	void _map_set_edge_connection_margin(const RID &map, double margin) override;
	double _map_get_edge_connection_margin(const RID &map) const override;
	void _map_set_link_connection_radius(const RID &map, double radius) override;
	double _map_get_link_connection_radius(const RID &map) const override;
	PackedVector3Array _map_get_path(const RID &map, const Vector3 &origin, const Vector3 &destination, bool optimize, int64_t navigation_layers) const override;
	Vector3 _map_get_closest_point_to_segment(const RID &map, const Vector3 &start, const Vector3 &end, bool use_collision) const override;
	Vector3 _map_get_closest_point(const RID &map, const Vector3 &to_point) const override;
	Vector3 _map_get_closest_point_normal(const RID &map, const Vector3 &to_point) const override;
	RID _map_get_closest_point_owner(const RID &map, const Vector3 &to_point) const override;
	TypedArray<RID> _map_get_links(const RID &map) const override;
	TypedArray<RID> _map_get_regions(const RID &map) const override;
	TypedArray<RID> _map_get_agents(const RID &map) const override;
	void _map_force_update(const RID &map) override;
	void _query_path_extension(const NavigationServer3DExtensionPathQueryParameters *parameters, NavigationServer3DExtensionPathQueryResult *result) const override;
	RID _region_create() override;
	void _region_set_enter_cost(const RID &region, double enter_cost) override;
	double _region_get_enter_cost(const RID &region) const override;
	void _region_set_travel_cost(const RID &region, double travel_cost) override;
	double _region_get_travel_cost(const RID &region) const override;
	void _region_set_owner_id(const RID &region, int64_t owner_id) override;
	int64_t _region_get_owner_id(const RID &region) const override;
	bool _region_owns_point(const RID &region, const Vector3 &point) const override;
	void _region_set_map(const RID &region, const RID &map) override;
	RID _region_get_map(const RID &region) const override;
	void _region_set_navigation_layers(const RID &region, int64_t navigation_layers) override;
	int64_t _region_get_navigation_layers(const RID &region) const override;
	void _region_set_transform(const RID &region, const Transform3D &transform) override;
	void _region_set_navigation_mesh(const RID &region, const Ref<NavigationMesh> &navigation_mesh) override;
	void _region_bake_navigation_mesh(const Ref<NavigationMesh> &navigation_mesh, Node *root_node) override;
	int64_t _region_get_connections_count(const RID &region) const override;
	Vector3 _region_get_connection_pathway_start(const RID &region, int64_t connection) const override;
	Vector3 _region_get_connection_pathway_end(const RID &region, int64_t connection) const override;
	RID _link_create() override;
	void _link_set_map(const RID &link, const RID &map) override;
	RID _link_get_map(const RID &link) const override;
	void _link_set_bidirectional(const RID &link, bool bidirectional) override;
	bool _link_is_bidirectional(const RID &link) const override;
	void _link_set_navigation_layers(const RID &link, int64_t navigation_layers) override;
	int64_t _link_get_navigation_layers(const RID &link) const override;
	void _link_set_start_location(const RID &link, const Vector3 &location) override;
	Vector3 _link_get_start_location(const RID &link) const override;
	void _link_set_end_location(const RID &link, const Vector3 &location) override;
	Vector3 _link_get_end_location(const RID &link) const override;
	void _link_set_enter_cost(const RID &link, double enter_cost) override;
	double _link_get_enter_cost(const RID &link) const override;
	void _link_set_travel_cost(const RID &link, double travel_cost) override;
	double _link_get_travel_cost(const RID &link) const override;
	void _link_set_owner_id(const RID &link, int64_t owner_id) override;
	int64_t _link_get_owner_id(const RID &link) const override;
	RID _agent_create() override;
	void _agent_set_map(const RID &agent, const RID &map) override;
	RID _agent_get_map(const RID &agent) const override;
	void _agent_set_neighbor_distance(const RID &agent, double distance) override;
	void _agent_set_max_neighbors(const RID &agent, int64_t count) override;
	void _agent_set_time_horizon(const RID &agent, double time) override;
	void _agent_set_radius(const RID &agent, double radius) override;
	void _agent_set_max_speed(const RID &agent, double max_speed) override;
	void _agent_set_velocity(const RID &agent, const Vector3 &velocity) override;
	void _agent_set_target_velocity(const RID &agent, const Vector3 &target_velocity) override;
	void _agent_set_position(const RID &agent, const Vector3 &position) override;
	void _agent_set_ignore_y(const RID &agent, bool ignore_y) override;
	bool _agent_is_map_changed(const RID &agent) const override;
	void _agent_set_callback(const RID &agent, int64_t object_id, const StringName &method, const Variant &userdata) override;
	void _free(const RID &rid) override;
	void _set_active(bool active) override;
	void _process(double delta_time) override;
};

class ExampleNavigationServerFactory : public Object {
	GDCLASS(ExampleNavigationServerFactory, Object);

protected:
	static void _bind_methods();

public:
	ExampleNavigationServer *create_server() { return memnew(ExampleNavigationServer); }
};

#endif // EXAMPLE_NAVIGATION_SERVER_H
