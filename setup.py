import subprocess

from setuptools import setup, Extension

setup(
    name="ojichat",
    author="Lapis256",
    version="1.0.0",
    license="MIT",
    url="https://github.com/Lapis256/ojichat-python",
    description="ojichatのPythonラッパーです",
    python_requires=">=3.6.1",
    setup_requires=["setuptools-golang"],
    ext_modules=[Extension("ojichat", ["ojichat/ojichat.go"])],
    build_golang={"root": "github.com/Lapis256/ojichat-python"}
)
