from ctypes import CDLL
import importlib.util
from pathlib import Path


def get_package_path(package_name):
    spec = importlib.util.find_spec(package_name)
    if spec is None:
        raise ImportError(f"Package '{package_name}' not found")
    return spec.origin


package_name = "science4ai"
try:
    package_path = get_package_path(package_name)
    path = Path(package_path)
    print(f"The path of package '{package_name}' is: {path.parent}")
    dll = CDLL(path.parent / "science4ai.dll")
    dll.science4ai()
except ImportError as e:
    print(e)
