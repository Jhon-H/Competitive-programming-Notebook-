int getCompressedIndex(int a) {
	return lower_bound(indices.begin(), indices.end(), a) - indices.begin();
}

sort(indices.begin(), indices.end());
indices.erase(unique(indices.begin(), indices.end()), indices.end());