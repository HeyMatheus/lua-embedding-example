#include <iostream>
#include <lua.hpp>
#include <filesystem>

using namespace std;

bool CheckLua(lua_State* L, int r) {
	if (r != LUA_OK) {
		string err = lua_tostring(L, -1);
		cout << err << endl;
		return false;
	}
	return true;
}

int main() {
	if (!filesystem::is_directory("scripts")) {
		cout << "[ERROR] \"scripts\" directory doesn't exist." << endl;
		return false;
	}

	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	if (CheckLua(L, luaL_dofile(L, "scripts/HelloWorld.lua"))) {
		lua_getglobal(L, "Boot");
		CheckLua(L, lua_pcall(L, 0, 0, 0));
	}

	lua_close(L);
	return 0;
}
