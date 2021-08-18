import platform
import sys

from setuptools import setup, Extension

if sys.platform != "win32" and platform.python_implementation() == "CPython":
    try:
        import wheel.bdist_wheel
    except ImportError:
        cmdclass = {}
    else:
        class bdist_wheel(wheel.bdist_wheel.bdist_wheel):
            def finalize_options(self) -> None:
                self.py_limited_api = f"cp3{sys.version_info[1]}"
                super().finalize_options()

        cmdclass = {"bdist_wheel": bdist_wheel}
else:
    cmdclass = {}

setup(
    name="ojichat",
    author="Lapis256",
    version="1.0.0",
    license="MIT",
    url="https://github.com/Lapis256/ojichat-python",
    description="ojichatのPythonラッパーです",
    python_requires=">=3.6.1",
    setup_requires=["setuptools-golang"],
    build_golang={"root": "github.com/Lapis256/ojichat-python"}, 
    ext_modules=[Extension(
        "ojichat", ["ojichat/ojichat.go"],
        py_limited_api=True, define_macros=[("Py_LIMITED_API", None)],
    )],
    cmdclass=cmdclass
)

