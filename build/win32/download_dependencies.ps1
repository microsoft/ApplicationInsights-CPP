Param(
	[string]$dependencyName,
	[string]$dependencyRootUri,
	[string]$rootPath 
)

$forceUpdate = $false
$dependencyPath = [System.IO.Path]::Combine($rootPath, ".deps")
if (!(Test-Path -path $dependencyPath) -or $forceUpdate) {
	[Console]::WriteLine("Creating folder " + $dependencyPath)
    $(MkDir $dependencyPath).Attributes = "Hidden"
    $forceUpdate = $true
} else {
    [Console]::WriteLine("Folder " + $dependencyPath + " already exists")
}

$downloadUri = $dependencyRootUri + $dependencyName
$dependency = [System.IO.Path]::Combine($dependencyPath, $dependencyName)
if (!(Test-Path -path $dependency) -or $forceUpdate) {
    [Console]::WriteLine("Downloading " + $downloadUri)
	$webClient = New-Object System.Net.WebClient
	$webclient.DownloadFile($downloadUri, $dependency)
	$forceUpdate = $true
} else {
    [Console]::WriteLine("Dependency " + $dependency + " already exists")
}

$shell = New-Object -COM Shell.Application
$zip = $shell.Namespace($dependency)
foreach($item in $zip.items())
{
    $fullPath = [System.IO.Path]::Combine($rootPath, $item.Name)
    if (!(Test-Path -path $dependency) -or $forceUpdate) {
	    [Console]::WriteLine("Unzipping " + $item.Name)
    	$shell.Namespace($rootPath).CopyHere($item, 0x14)
	} else {
		[Console]::WriteLine("Item " + $item.Name + " already exists")
	}
}
