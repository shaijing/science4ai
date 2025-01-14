import sys

gil_state = sys._is_gil_enabled()
if not gil_state:
    print("Free-threading is enabled (GIL is disabled).")
else:
    print("Free-threading is not enabled (GIL is active).")
